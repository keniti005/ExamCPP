#pragma once
#include "GameObject.h"
#include "globals.h"

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
    void SetPos(float x, float y) { x_ = x, y_ = y; }//“G‚ÌÀ•W‚ğİ’è
    Rect GetRect() const { return{ x_,y_,imageSize_.x,imageSize_.y }; }
    void SetMaxMovex(float xmax) { xMoveMax_ = xmax; }
    void SetXorigin(float x) { xorigin_ = x; }

//    void SetID(int id) { ID_ = id; }//“G‚ÌID‚ğİ’è
protected:
private:
    int hImage_;//“G‚Ì‰æ‘œƒnƒ“ƒhƒ‹
    float x_, y_;//“G‚ÌÀ•W
    float speed_;//“G‚ÌˆÚ“®‘¬“x
    Point imageSize_;
    float xMoveMax_;//‰¡•ûŒü‚ÌˆÚ“®Å‘å’l
    float xorigin_;
    float moveTime_;
    int ID_;//“G‚ÌID
    ETYPE type_;//“G‚Ìí—Ş
};

