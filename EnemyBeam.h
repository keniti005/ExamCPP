#pragma once
#include "GameObject.h"
#include "globals.h"
class EnemyBeam :
    public GameObject
{
public:
public:
    EnemyBeam();
    EnemyBeam(float x,float y);
    EnemyBeam(Point pos_);
    ~EnemyBeam();
    void Update() override;
    void Draw() override;

    void SetPos(float x, float y) { pos_.x = x, pos_.y = y; }//“G‚ÌÀ•W‚ğİ’è
    void SetPos(const Point& pos) { pos_ = pos; }//’e‚ÌÀ•W‚ğİ’è
    void SetFired(bool fired) { isFired_ = fired; }//”­Ëó‘Ô‚ğ•Û‘¶
    bool IsFired() const { return isFired_; }
    Rect GetRect() const { return{ pos_.x,pos_.y,imageSize_.x,imageSize_.y }; }
protected:
private:
    int hImage_;//“G‚Ì‰æ‘œƒnƒ“ƒhƒ‹
    Point pos_;
    float speed_;//“G‚ÌˆÚ“®‘¬“x
    bool isFired_;
    Point imageSize_;

};

