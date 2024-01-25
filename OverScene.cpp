#include "OverScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

OverScene::OverScene(GameObject* parent)
	:GameObject(parent,"GameOver"),oImage_(-1)
{
}

void OverScene::Initialize()
{
	oImage_ = Image::Load("Image\\GameOver.png");
	assert(oImage_ >= 0);

	transform_.scale_ = { 1.25,1.25,1.25 };
}

void OverScene::Update()
{
	if (Input::IsKeyUp(DIK_RETURN)) {
		SceneManager* s = (SceneManager*)FindObject("SceneManager");
		s->ChangeScene(TITLE_SCENE);
	}
}

void OverScene::Draw()
{
	Image::SetTransform(oImage_, transform_);
	Image::Draw(oImage_);
}

void OverScene::Release()
{
}
