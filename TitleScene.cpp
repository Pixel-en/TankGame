#include "TitleScene.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene")
{
}

void TitleScene::Initialize()
{
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
}

void TitleScene::Release()
{
}
