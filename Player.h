#pragma once
#include "GameObject.h"
#include "globals.h"

class Bullet;//�O���錾

class Player :
    public GameObject
{
public:
    Player();
    ~Player();
    void Update() override;
    void Draw() override;
    void Shoot();//�e�𔭎˂���֐�
    Rect GetRect() const { return { x_,y_,imageSize_.x,imageSize_.y }; }//�v���C���[�̋�`���擾
    std::vector<Bullet*> GetAllBullets() const { return bullets_; }//���ׂĂ̒e���擾
protected:

private:
    int hImage_;//�v���C���[�̉摜�o���h��
    float x_, y_;//�v���C���[�̍��W
    float speed_;//�v���C���[�̈ړ����x
    Point imageSize_;
    std::vector<Bullet*> bullets_;//�v���C���[�����˂����e�̃x�N�^�[
    Bullet* GetActiveBullet();
};

