#pragma once
#include "Engine/GameObject.h"

class Bullet : public GameObject
{
	int hModel_;

	float bulletspeed_;
	XMFLOAT3 movedir_; 

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Bullet(GameObject* parent);
	~Bullet();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;


	void SetMoveDir(XMFLOAT3 _move) { movedir_ = _move; }
	void SetSpeed(float _speed) { bulletspeed_ = _speed; }
};
