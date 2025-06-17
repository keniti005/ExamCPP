#pragma once
#include "GameObject.h"
#include <vector>

class Player;//前方宣言
class Enemy;//前方宣言

class Stage :
    public GameObject
{
public:
    Stage();
    ~Stage();
    void Update() override;
    void Draw() override;
protected:

private:
    Player* player_;//プレイヤーオブジェクト
    std::vector<Enemy*> enemy_;//敵オブジェクト
    Enemy* enemyBeam_;
    int hBackgraound;
};

