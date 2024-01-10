#pragma once
#include "Engine/GameObject.h"

class Tank : public GameObject
{
    int tbModel_;

    XMVECTOR front_;
    double speed_;



public:
    //�R���X�g���N�^
    Tank(GameObject* parent);

    //�f�X�g���N�^
    ~Tank();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};