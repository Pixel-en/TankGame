#include "Tank.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Ground.h"
#include "TankHead.h"

Tank::Tank(GameObject* parent)
	:GameObject(parent,"Tank"),tbModel_(-1)
{
	front_ = { 0,0,1,0 };
	speed_ = 0.05;
}

Tank::~Tank()
{
}

void Tank::Initialize()
{
	Instantiate<TankHead>(this);
	tbModel_ = Model::Load("Model\\TankBody.fbx");
}

void Tank::Update()
{
	if (Input::IsKey(DIK_A))
		transform_.rotate_.y -= 1.0f;
	if (Input::IsKey(DIK_D))
		transform_.rotate_.y += 1.0f;

	XMMATRIX rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
	XMVECTOR rotVec = XMVector3TransformCoord(front_, rotY);

	XMVECTOR move;
	move = speed_ * rotVec;
	XMVECTOR pos = XMLoadFloat3(&transform_.position_);

	if (Input::IsKey(DIK_W))
		pos += move;

	if (Input::IsKey(DIK_S))
		pos -= move;

	XMStoreFloat3(&transform_.position_, pos);

	Ground* pGround = (Ground*)FindObject("Ground");
	int hGmodel = pGround->GetModelHandle();
	
	RayCastData data;
	data.start = transform_.position_;
	data.start.y = 0;
	data.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &data);
	
	if (data.hit) {
		transform_.position_.y = -data.dist;
	}

}

void Tank::Draw()
{
	Model::SetTransform(tbModel_, transform_);
	Model::Draw(tbModel_);
}

void Tank::Release()
{
}
