#include "Bullet.h"
#include "Engine/Model.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hModel_(-1)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	hModel_= Model::Load("Model\\box.fbx");
	assert(hModel_ >= 0);
}

void Bullet::Update()
{
	transform_.position_.x = transform_.position_.x + movedir_.x * bulletspeed_;
	transform_.position_.y = transform_.position_.y + movedir_.y * bulletspeed_;
	transform_.position_.z = transform_.position_.z + movedir_.z * bulletspeed_;
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
