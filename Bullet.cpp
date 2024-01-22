#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/Debug.h"
#include "Engine/Collider.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hModel_(-1)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	hModel_= Model::Load("Model\\bullet.fbx");
	assert(hModel_ >= 0);

	SphereCollider* collision = new SphereCollider({ 0,0,0 }, 0.3f);
	AddCollider(collision);


}

void Bullet::Update()
{
	transform_.position_.x = transform_.position_.x + movedir_.x * bulletspeed_;
	transform_.position_.y = transform_.position_.y + movedir_.y * bulletspeed_;
	transform_.position_.z = transform_.position_.z + movedir_.z * bulletspeed_;
	movedir_.y -= 0.025f;
	if (transform_.position_.y <= -5.0f) {
		KillMe();
		Debug::Log("Kill", true);
	}
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
