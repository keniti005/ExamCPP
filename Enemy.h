#pragma once
#include "GameObject.h"
#include "globals.h"

class EnemyBeam;

enum ETYPE
{
    ZAKO,MID,KNIGHT,BOSS,MAX_ETYPE
};

class Enemy :
    public GameObject
{
public:
    Enemy(int id, ETYPE type);
    Enemy();
    ~Enemy();
    void Update() override;
    void Draw() override;
    void SetPos(float x, float y) { x_ = x, y_ = y; }//敵の座標を設定
    Rect GetRect() const { return{ x_,y_,imageSize_.x,imageSize_.y }; }
    void SetMaxMovex(float xmax) { xMoveMax_ = xmax; }
    void SetXorigin(float x) { xorigin_ = x; }
    std::vector<EnemyBeam*> GetAllEnemyBeams() const { return EnemyBeams_; }//すべての弾を取得

//    void SetID(int id) { ID_ = id; }//敵のIDを設定
protected:
private:
    int hImage_;//敵の画像ハンドル
    float x_, y_;//敵の座標
    float speed_;//敵の移動速度
    Point imageSize_;
    float xMoveMax_;//横方向の移動最大値
    float xorigin_;
    float moveTime_;
    int ID_;//敵のID
    ETYPE type_;//敵の種類
    std::vector<EnemyBeam*> EnemyBeams_;//プレイヤーが発射した弾のベクター
    EnemyBeam* GetActiveEnemyBeam();
};

