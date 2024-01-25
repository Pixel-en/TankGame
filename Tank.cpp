#include "Tank.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Ground.h"
#include "TankHead.h"
#include "Engine/Debug.h"
#include "Engine/Camera.h"
#include "Engine/Collider.h"

//ÉJÉÅÉâêßå‰
enum CAM_TYPE
{
	FIXED_TYPE,	//å≈íË
	TPS_NOROT_TYPE, //ÇRêlèÃâÒì]Ç»Çµ
	TPS_TYPE,	//ÇRêlèÃ
	FPS_TYPE,	//ÇPêlèÃ
	MAX_TYPE	//î‘ï∫
};

Tank::Tank(GameObject* parent)
	:GameObject(parent,"Tank"),tbModel_(-1), camState_(CAM_TYPE::FIXED_TYPE)
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
	assert(tbModel_ >= 0);

	SphereCollider* collision = new SphereCollider({ 0,0,0 }, 1.5f);
	AddCollider(collision);
}

void Tank::Update()
{


	if (Input::IsKey(DIK_A))
		transform_.rotate_.y -= 1.0f;
	if (Input::IsKey(DIK_D))
		transform_.rotate_.y += 1.0f;

	float dir = 0;
	if (Input::IsKey(DIK_W))
	{
		dir = 1.0;

	}
	if (Input::IsKey(DIK_S))
	{
		dir = -1.0;
	}

	if (Input::IsKey(DIK_LSHIFT))
		speed_ = 1.0;

	XMMATRIX rotY = XMMatrixIdentity();
	XMVECTOR rotVec{ 0.0,0.0 };
	XMVECTOR move{ 0.0,0.0 };
	rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
	rotVec = XMVector3TransformCoord(front_, rotY);


	move = speed_ * rotVec;
	XMVECTOR pos = XMLoadFloat3(&transform_.position_);

	pos = pos + dir * move;



#ifdef DEBUG
	if (Input::IsKeyDown(DIK_0)) {
		Debug::Log("x=");
		Debug::Log(transform_.position_.x,true);
		Debug::Log("y=");
		Debug::Log(transform_.position_.y,true);
		Debug::Log("z=");
		Debug::Log(transform_.position_.z,true);
	}
#endif
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

	if (Input::IsKeyDown(DIK_Z))
	{
		camState_++;
		//camState_ = (++camState_) % (CAM_TYPE::MAX);
		if (camState_ == CAM_TYPE::MAX_TYPE)
			camState_ = CAM_TYPE::FIXED_TYPE;
	}

	switch (camState_)
	{
	case CAM_TYPE::FIXED_TYPE:
	{
		Camera::SetPosition(XMFLOAT3(0, 20, -20));
		Camera::SetTarget(XMFLOAT3(0, 0, 0));
		break;
	}
	case CAM_TYPE::TPS_NOROT_TYPE:
	{
		XMFLOAT3 camPos = transform_.position_;
		camPos.y = transform_.position_.y + 20.0f;
		camPos.z = transform_.position_.z - 10.0f;
		Camera::SetPosition(camPos);
		Camera::SetTarget(transform_.position_);
		break;
	}
	case CAM_TYPE::TPS_TYPE:
	{
		//Camera::SetPosition(XMFLOAT3(0, 20, -30));
		Camera::SetTarget(transform_.position_);
		
		XMVECTOR vEye{ 0,5,-10,0 };
		vEye = XMVector3TransformCoord(vEye, rotY);
		XMFLOAT3 camPos;
		XMStoreFloat3(&camPos, pos + vEye);
		Camera::SetPosition(camPos);
		break;
	}
	case CAM_TYPE::FPS_TYPE:
	{
		Camera::SetPosition(transform_.position_);
		XMFLOAT3 camTarget;

		XMStoreFloat3(&camTarget, pos + move);
		Camera::SetTarget(camTarget);
		break;
	}
	default:
		break;
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
