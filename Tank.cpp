#include "Tank.h"
#include "Engine/Model.h"

Tank::Tank(GameObject* parent)
	:GameObject(parent,"Tank"),thModel_(-1),tbModel_(-1)
{
}

Tank::~Tank()
{
}

void Tank::Initialize()
{
	thModel_ = Model::Load("Model\\TankHead.fbx");
	tbModel_ = Model::Load("Model\\TankBody.fbx");
}

void Tank::Update()
{
}

void Tank::Draw()
{
}

void Tank::Release()
{
}
