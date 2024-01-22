#include "PlayScene.h"
#include "Ground.h"
#include "Enemy.h"
#include "Engine/Camera.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"
#include "Engine/Debug.h"

PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	player=Instantiate<Tank>(this);

	for (int i = 0; i < 50; i++) {
		Enemy* e = Instantiate<Enemy>(this);
		e->SetPosition(((float)rand() / RAND_MAX * 2.0 - 1.0) * 25, 5, ((float)rand() / RAND_MAX * 2.0 - 1.0) * 25);
	}

	framecnt = 0;
}

void PlayScene::Update()
{
	//デバッグで更新
	if (framecnt == 60) {
		Debug::Log(FindChildObjectNum("Enemy"),TRUE);
		framecnt = 0;
	}
	else
		framecnt++;

}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
