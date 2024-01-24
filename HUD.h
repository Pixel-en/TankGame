#pragma once
#include "Engine/GameObject.h"


class HUD : public GameObject
{
    int hHUD;
    int hNumbers_;

    Transform tHud_;

    Transform tNumbers_[3];

    std::string ConstructEnemyNumberString();

public:
    //�R���X�g���N�^
    HUD(GameObject* parent);

    //�f�X�g���N�^
    ~HUD();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

};