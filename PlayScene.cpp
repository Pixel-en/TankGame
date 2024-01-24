#include "PlayScene.h"
#include "Ground.h"
#include "Enemy.h"
#include "Engine/Camera.h"
#include "Engine/Input.h"
#include "HUD.h"


PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	player=Instantiate<Tank>(this);

	EnemyNum_ = ENEMIES;
	
	for (int i = 0; i < EnemyNum_; i++) {
		Enemy* e = Instantiate<Enemy>(this);
		e->SetPosition(((float)rand() / RAND_MAX * 2.0 - 1.0) * 25, 5, ((float)rand() / RAND_MAX * 2.0 - 1.0) * 25);
	}

	Instantiate<HUD>(this);

}

void PlayScene::Update()
{


}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
