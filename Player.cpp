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
}

Player::Player()
	:GameObject(), hImage_(-1), x_(0), y_(0), speed_(0)
{
	hImage_ = LoadGraph("Assets\\tiny_ship5.png");//�v���C���[�̉摜��ǂݍ���
	x_ = PLAYER_INIT_X;
	y_ = PLAYER_INIT_Y;
	speed_ = PLAYER_INIT_SPEED;
	assert(hImage_ > 0);
	AddGameObject(this);
}

Player::~Player()
{
}

void Player::Update()
{
	float dt = GetDeltaTime();//�t���[���Ԃ̎��ԍ����擾
	if (Input::IsKeepKeyDown(KEY_INPUT_LEFT))
	{
		x_ = x_ - speed_ * dt;//���Ɉړ�
	}
	if (Input::IsKeepKeyDown(KEY_INPUT_RIGHT))
	{
		x_ = x_ + speed_ * dt;//�E�Ɉړ�
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
			new Bullet(x_ + BULLET_IMAGE_MARGIN, y_);//�e�𔭎�
			bulletTimer = BULLET_INTERVAL;//�e�̔��ˊ��o�����Z�b�g
		}
	}
}

void Player::Draw()
{
	//�v���C���[�̉摜��`��
	DrawExtendGraph(x_, y_, x_ + PLAYER_IMAGE_WIDTH, y_ + PLAYER_IMAGE_HEIGHT, hImage_, TRUE);
}
