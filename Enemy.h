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
    void SetPos(float x, float y) { x_ = x, y_ = y; }//�G�̍��W��ݒ�
    Rect GetRect() const { return{ x_,y_,imageSize_.x,imageSize_.y }; }
    void SetMaxMovex(float xmax) { xMoveMax_ = xmax; }
    void SetXorigin(float x) { xorigin_ = x; }
    std::vector<EnemyBeam*> GetAllEnemyBeams() const { return EnemyBeams_; }//���ׂĂ̒e���擾

//    void SetID(int id) { ID_ = id; }//�G��ID��ݒ�
protected:
private:
    int hImage_;//�G�̉摜�n���h��
    float x_, y_;//�G�̍��W
    float speed_;//�G�̈ړ����x
    Point imageSize_;
    float xMoveMax_;//�������̈ړ��ő�l
    float xorigin_;
    float moveTime_;
    int ID_;//�G��ID
    ETYPE type_;//�G�̎��
    std::vector<EnemyBeam*> EnemyBeams_;//�v���C���[�����˂����e�̃x�N�^�[
    EnemyBeam* GetActiveEnemyBeam();
};

