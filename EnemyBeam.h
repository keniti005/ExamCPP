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

    void SetPos(float x, float y) { pos_.x = x, pos_.y = y; }//�G�̍��W��ݒ�
    void SetPos(const Point& pos) { pos_ = pos; }//�e�̍��W��ݒ�
    void SetFired(bool fired) { isFired_ = fired; }//���ˏ�Ԃ�ۑ�
    bool IsFired() const { return isFired_; }
    Rect GetRect() const { return{ pos_.x,pos_.y,imageSize_.x,imageSize_.y }; }
protected:
private:
    int hImage_;//�G�̉摜�n���h��
    Point pos_;
    float speed_;//�G�̈ړ����x
    bool isFired_;
    Point imageSize_;

};

