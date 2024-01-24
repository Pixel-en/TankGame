#pragma once
#include "Engine/GameObject.h"
#include "Tank.h"

const int ENEMIES{ 50 };

class PlayScene : public GameObject
{
	Tank *player;

	int EnemyNum_;

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	PlayScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	void DescEnemy() { EnemyNum_--; }
	bool IsEnemyLeft() { return EnemyNum_ > 0; }
	int  GetEnemyNum() { return EnemyNum_; }
};