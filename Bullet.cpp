#include "Bullet.h"
#include "globals.h"
#include "DxLib.h"
#include <string>

namespace
{
	const int BULLET_IMAGE_WIDTH = 13;//�e�̉摜�̕�
	const int BULLET_IMAGE_HEIGHT = 33;//�e�̉摜�̍���
	const float BULLET_INIT_SPEED = 200.0f;//�e�̏����ړ����x
	const std::string BULLET_IMAGE_PATH = "Assets\\laserBlue03.png";//�e�̉摜�p�X
}

Bullet::Bullet()
	:GameObject(), hImage_(-1), x_(0), y_(0), speed_(0), isFired_(false), imageSize_({ BULLET_IMAGE_WIDTH,BULLET_IMAGE_HEIGHT })
{
	hImage_ = LoadGraph(BULLET_IMAGE_PATH.c_str());//�e�̉摜��ǂݍ���
	speed_ = BULLET_INIT_SPEED;//�ړ����x
	AddGameObject(this);
}

Bullet::Bullet(float x, float y)
	:GameObject(), hImage_(-1), x_(0), y_(0), speed_(0), isFired_(false), imageSize_({ BULLET_IMAGE_WIDTH,BULLET_IMAGE_HEIGHT })
{
	hImage_ = LoadGraph(BULLET_IMAGE_PATH.c_str());//�e�̉摜��ǂݍ���
	speed_ = BULLET_INIT_SPEED;//�ړ����xx
	isFired_ = LoadGraph(BULLET_IMAGE_PATH.c_str());
	x_ = x;
	y_ = y;
	AddGameObject(this);
}

Bullet::~Bullet()
{
	if (hImage_ != -1)
	{
		DeleteGraph(hImage_);//�摜�̃n���h�����
	}
	hImage_ = -1;//�摜�o���h���𖳌���
}

void Bullet::Update()
{
	float dt = GetDeltaTime();
	y_ = y_ - (speed_ * dt);//�e�̈ړ�
	if (y_ < 0)
	{
		isFired_ = false;//��ʔ����ɏo����e��������Ԃɂ���
	}
}

void Bullet::Draw()
{
	if (isFired_)
	{
		DrawExtendGraphF(x_, y_, x_ + imageSize_.x, y_ + imageSize_.y, hImage_, FALSE);
	}
}

void Bullet::SetPos(float x, float y)
{
	x_ = x;
	y_ = y;
}
