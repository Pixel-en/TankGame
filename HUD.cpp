#include "HUD.h"
#include "Engine/Image.h"
#include "PlayScene.h"
#include <string>

std::string HUD::ConstructEnemyNumberString()
{
	int enemies = ((PlayScene*)GetParent())->GetEnemyNum();
	return std::to_string(enemies);
}

HUD::HUD(GameObject* parent)
	:GameObject(parent,"HUD"),hHUD(-1),hNumbers_(-1)
{
}

HUD::~HUD()
{
}

void HUD::Initialize()
{
	hHUD=Image::Load("Image\\HUD.png");
	assert(hHUD >= 0);
	hNumbers_=Image::Load("Image\\Numbers.png");
	assert(hNumbers_ >= 0);

	for (int i = 0; i < 2; i++)
	{
		Transform trans;
		trans.position_ = { -0.8f + 0.03f * (float)i, 0.93f, 0.0f };
		trans.scale_ = { 0.5,0.5,1 };
		tNumbers_[i] = trans;
	}

}

void HUD::Update()
{
	tHud_.scale_ = { 0.5,0.5,1 };
	tHud_.position_ = { -0.8,0.93,0 };
}

void HUD::Draw()
{
	Image::SetTransform(hHUD, tHud_);
	Image::Draw(hHUD);

	std::string temp = ConstructEnemyNumberString();

	for (int i = 0; i < temp.size(); i++) {
		int Rn = temp[i] - '0';
		Image::SetTransform(hNumbers_, tNumbers_[i]);
		Image::SetRect(hNumbers_, 0 + 51.2f * Rn, 0, 51.2f, 60);
		Image::Draw(hNumbers_);
	}
}

void HUD::Release()
{
}

