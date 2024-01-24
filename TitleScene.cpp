#include "TitleScene.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/Image.h"

TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene"),tImage_(-1)
{
}

void TitleScene::Initialize()
{
	tImage_ = Image::Load("Image\\tankgame_title.jpg");
	assert(tImage_ >= 0);

	transform_.scale_ = { 1.25,1.25,1.25 };
}

void TitleScene::Update()
{
	if (Input::IsKeyUp(DIK_RETURN)) {
		SceneManager* s = (SceneManager*)FindObject("SceneManager");
		s->ChangeScene(PLAY_SCENE);
	}

}

void TitleScene::Draw()
{
	Image::SetTransform(tImage_, transform_);
	Image::Draw(tImage_);
}

void TitleScene::Release()
{
}
