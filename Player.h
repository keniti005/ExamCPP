#pragma once
#include "GameObject.h"

class Bullet;//�O���錾

class Player :
    public GameObject
{
    int hImage_;//�v���C���[�̉摜�o���h��
    float x_, y_;//�v���C���[�̍��W
    float speed_;//�v���C���[�̈ړ����x
    std::vector<Bullet*> bullets_;//�v���C���[�����˂����e�̃x�N�^�[
public:
    Player();
    ~Player();
    void Update() override;
    void Draw() override;
};

