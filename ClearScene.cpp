#include "ClearScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent, "GameClear"), cImage_(-1)
{
}

void ClearScene::Initialize()
{
	cImage_ = Image::Load("Image\\GameClear.png");
	assert(cImage_ >= 0);

	transform_.scale_ = { 1.25,1.25,1.25 };
}

void ClearScene::Update()
{
	if (Input::IsKeyUp(DIK_RETURN)) {
		SceneManager* s = (SceneManager*)FindObject("SceneManager");
		s->ChangeScene(TITLE_SCENE);
	}
}

void ClearScene::Draw()
{
	Image::SetTransform(cImage_, transform_);
	Image::Draw(cImage_);
}

void ClearScene::Release()
{
}
