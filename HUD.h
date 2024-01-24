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
    //コンストラクタ
    HUD(GameObject* parent);

    //デストラクタ
    ~HUD();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

};