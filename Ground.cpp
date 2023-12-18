#include "Ground.h"
#include "Engine/Model.h"

Ground::Ground(GameObject* parent)
	:GameObject(parent, "Ground"),gModel_(-1)
{
}

Ground::~Ground()
{
}

void Ground::Initialize()
{
	gModel_ = Model::Load("Model\\Ground.fbx");
	assert(gModel_ >= 0);
}

void Ground::Update()
{
}

void Ground::Draw()
{
	Model::SetTransform(gModel_, transform_);
	Model::Draw(gModel_);
}

void Ground::Release()
{
}
