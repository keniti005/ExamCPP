#include "Player.h"
#include "DxLib.h"
#include "globals.h"
#include "Input.h"
#include "Bullet.h"
#include <assert.h>

namespace
{
	const int PLAYER_IMAGE_WIDTH = 48;//�v���C���[�̉摜�̕�
	const int PLAYER_IMAGE_HEIGHT = 48;//�v���C���[�̉摜�̍���
	const int PLAYER_BASE_MARGIN = 32;//�v���C���[�̊�}�[�W��
	const float PLAYER_INIT_X = WIN_WIDTH / 2 - PLAYER_IMAGE_WIDTH;//�v���C���[�̏���X���W
	const float PLAYER_INIT_Y = WIN_HEIGHT - PLAYER_IMAGE_HEIGHT - PLAYER_BASE_MARGIN;//�v���C���[�̏���Y���W
	const float PLAYER_INIT_SPEED = 200.0f;//�v���C���[�̏����ړ����x
	const int BULLET_IMAGE_MARGIN = 17;//�e�̉摜�̃}�[�W��
	const float BULLET_INTERVAL = 0.5f;//�e�̔��ˊԊu
	const int PLAYER_BULLET_NUM = 5;//�v���C���[�������ɔ��˂ł���e�̐�
}


Player::Player()
	:GameObject(), hImage_(-1), x_(0), y_(0), speed_(0),imageSize_({ PLAYER_IMAGE_WIDTH ,PLAYER_IMAGE_HEIGHT })
{
	hImage_ = LoadGraph("Assets\\tiny_ship5.png");//�v���C���[�̉摜��ǂݍ���
	x_ = PLAYER_INIT_X;
	y_ = PLAYER_INIT_Y;
	speed_ = PLAYER_INIT_SPEED;
	for (int i = 0;i < PLAYER_BULLET_NUM;i++)
	{
		bullets_.push_back(new Bullet());//�e�̃x�N�^�[��������
	}

	assert(hImage_ > 0);
	AddGameObject(this);
}

Player::~Player()
{
	if (hImage_ != -1)
	{
		DeleteGraph(hImage_);//�摜�̃n���h�����
	}
}

void Player::Update()
{
	Point nextP = { x_,y_ };
	float dt = GetDeltaTime();//�t���[���Ԃ̎��ԍ����擾
	if (Input::IsKeepKeyDown(KEY_INPUT_LEFT))
	{
		nextP.x = x_ - speed_ * dt;//���Ɉړ�
	}
	if (Input::IsKeepKeyDown(KEY_INPUT_RIGHT))
	{
		nextP.x = x_ + speed_ * dt;//�E�Ɉړ�
	}

	if (nextP.x >= 0 && nextP.x + PLAYER_IMAGE_WIDTH <= WIN_WIDTH)
	{
		x_ = nextP.x;
		y_ = nextP.y;
	}

	static float bulletTimer = 0.0f;//�e�̃^�C�}�[
	if (bulletTimer > 0.0f)
	{
		bulletTimer -= dt;//�^�C�}�[����
	}

	if (Input::IsKeyDown(KEY_INPUT_SPACE))
	{
		if (bulletTimer <= 0.0f)
		{
			Shoot();//�e�𔭎�
			//new Bullet(x_ + BULLET_IMAGE_MARGIN, y_);//�e�𔭎�
			bulletTimer = BULLET_INTERVAL;//�e�̔��ˊ��o�����Z�b�g
		}
	}
}

void Player::Draw()
{
	//�v���C���[�̉摜��`��
	DrawExtendGraphF(x_, y_, x_ + PLAYER_IMAGE_WIDTH, y_ + PLAYER_IMAGE_HEIGHT, hImage_, TRUE);
}

//�e�����֐�
void Player::Shoot()
{
	//for (auto& itr : bullets_)
	//{
	//	if (itr->IsFired() == false)
	//	{
	//		itr->SetPos(x_ + BULLET_IMAGE_MARGIN, y_);
	//		itr->SetFired(true);
	//		break;
	//	}
	//}
	
	Bullet* bit = GetActiveBullet();
	if (bit != nullptr)
	{
		bit->SetPos(x_ + BULLET_IMAGE_MARGIN, y_);
		bit->SetFired(true);//�e�𔭎ˏ�Ԃɂ���
	}
}

Bullet* Player::GetActiveBullet()
{
	for (auto& itr : bullets_)
	{
		if (!itr->IsFired())
		{
			return itr;
		}
	}
	return nullptr;
}
