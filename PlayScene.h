#pragma once
#include "Engine/GameObject.h"
#include "Tank.h"

const int ENEMIES{ 50 };

class PlayScene : public GameObject
{
	Tank *player;

	int EnemyNum_;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	PlayScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	void DescEnemy() { EnemyNum_--; }
	bool IsEnemyLeft() { return EnemyNum_ > 0; }
	int  GetEnemyNum() { return EnemyNum_; }
};