#include "Enemy.h"
#include "DxLib.h"
#include <string>
#include <assert.h>

namespace
{
const int ENEMY_IMAGE_WIDTH = 48;//�G�[�̉摜�̕�
const int ENEMY_IMAGE_HEIGHT = 48;//�G�̉摜�̍���
const int PLAYER_BASE_MARGIN = 32;//�G�̊�}�[�W��
const float ENEMY_INIT_X = 100;//�G�̏���X���W
const float ENEMY_INIT_Y = 100;//�G�̏���Y���W
const float ENEMY_INIT_SPEED = 100.0f;//�G�̏����ړ����x
}

Enemy::Enemy()
	:GameObject(), hImage_(-1), x_(0), y_(0), speed_(0), isAlive_(true)
{
	hImage_ = LoadGraph("Assets\\tiny_ship10.png");
	assert(hImage_ > 0);
	x_ = ENEMY_INIT_X;//�������W
	y_ = ENEMY_INIT_Y;//�������W
	speed_ = ENEMY_INIT_SPEED;//�ړ����x
}

Enemy::Enemy(int id, ETYPE type)
	:GameObject(), hImage_(-1), x_(0), y_(0), speed_(0), isAlive_(true),ID_(id),type_(type)
{
	std::string imagePath[MAX_ETYPE] = 
	{
		"Assets\\tiny_ship10.png",
		"Assets\\tiny_ship18.png",
		"Assets\\tiny_ship16.png",
		"Assets\\tiny_ship9.png"
	};

	hImage_ = LoadGraph(imagePath[type_].c_str());
	assert(hImage_ > 0);
	x_ = ENEMY_INIT_X;//�������W
	y_ = ENEMY_INIT_Y;//�������W
	speed_ = ENEMY_INIT_SPEED;//�ړ����x
	//������������K�v������
	//ID_ = ;
	//type_ = ;
}

Enemy::~Enemy()
{
	if (hImage_ != -1)
	{
		DeleteGraph(hImage_);//�摜�̃n���h�����
	}
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	DrawExtendGraph(x_, y_, x_ + ENEMY_IMAGE_WIDTH, y_ + ENEMY_IMAGE_HEIGHT, hImage_, TRUE);
}
