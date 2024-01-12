#pragma once
#include "Engine/GameObject.h"

class Bullet : public GameObject
{
	int hModel_;

	float bulletspeed_;
	XMFLOAT3 movedir_; 

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Bullet(GameObject* parent);
	~Bullet();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;


	void SetMoveDir(XMFLOAT3 _move) { movedir_ = _move; }
	void SetSpeed(float _speed) { bulletspeed_ = _speed; }
};
