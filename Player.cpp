#include "Player.h"
#include "DxLib.h"
#include "globals.h"
#include "Input.h"
#include <assert.h>

namespace
{
	const int PLAYER_IMAGE_WIDTH = 48;//�v���C���[�̉摜�̕�
	const int PLAYER_IMAGE_HEIGHT = 48;//�v���C���[�̉摜�̍���
	const int PLAYER_BASE_MARGIN = 32;//�v���C���[�̊�}�[�W��
	const float PLAYER_INIT_X = WIN_WIDTH / 2 - PLAYER_IMAGE_WIDTH;//�v���C���[�̏���X���W
	const float PLAYER_INIT_Y = WIN_HEIGHT - PLAYER_IMAGE_HEIGHT - PLAYER_BASE_MARGIN;//�v���C���[�̏���Y���W
	const float PLAYER_INIT_SPEED = 5.0f;//�v���C���[�̏����ړ����x
}

Player::Player()
	:GameObject(), hImage_(-1), x_(0), y_(0), speed_(0)
{
	hImage_ = LoadGraph("Assets\\tiny_ship5.png");//�v���C���[�̉摜��ǂݍ���
	x_ = PLAYER_INIT_X;
	y_ = PLAYER_INIT_Y;
	speed_ = PLAYER_INIT_SPEED;
	assert(hImage_ > 0);
}

Player::~Player()
{
}

void Player::Update()
{
	if (Input::IsKeepKeyDown(KEY_INPUT_LEFT))
	{
		x_ -= speed_ * GetDeltaTime();//���Ɉړ�
	}
	if (Input::IsKeepKeyDown(KEY_INPUT_RIGHT))
	{
		x_ += speed_ * GetDeltaTime();//�E�Ɉړ�
	}
}

void Player::Draw()
{
	DrawExtendGraph(x_, y_, x_ + PLAYER_IMAGE_WIDTH, y_ + PLAYER_IMAGE_HEIGHT, hImage_, TRUE);
}
