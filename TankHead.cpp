#include "TankHead.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Bullet.h"

TankHead::TankHead(GameObject* parent)
	:GameObject(parent,"TankHead"),hModel_(-1)
{
}

TankHead::~TankHead()
{
}

void TankHead::Initialize()
{
	hModel_ = Model::Load("Model\\TankHead.fbx");
	assert(hModel_ >= 0);
}

void TankHead::Update()
{
	if (Input::IsKey(DIK_LEFT))
		transform_.rotate_.y -= 4.0f;
	if (Input::IsKey(DIK_RIGHT))
		transform_.rotate_.y += 4.0f;

	if (Input::IsKeyDown(DIK_SPACE) && FindObject("Bullet") == nullptr) {

		XMFLOAT3 cannonTopPos = Model::GetBonePosition(hModel_, "CannonPos");
		XMFLOAT3 cannonRootPos = Model::GetBonePosition(hModel_, "CannonRoot");

		XMVECTOR vtop = XMLoadFloat3(&cannonTopPos);
		XMVECTOR vroot = XMLoadFloat3(&cannonRootPos);
		XMVECTOR moveDir = vtop - vroot;
		moveDir = XMVector3Normalize(moveDir);

		XMFLOAT3 vmove;
		XMStoreFloat3(&vmove, moveDir);

		Bullet* pBullet = Instantiate<Bullet>(this->GetParent()->GetParent());
		pBullet->SetPosition(cannonTopPos);
		pBullet->SetMoveDir(vmove);
		pBullet->SetSpeed(0.3);
	}
}

void TankHead::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void TankHead::Release()
{
	
}
