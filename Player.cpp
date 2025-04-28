#include "Player.h"
#include "DxLib.h"

namespace
{
	const float PLAYER_INIT_X = 0.0f;//�v���C���[�̏���X���W
	const float PLAYER_INIT_Y = 0.0f;//�v���C���[�̏���Y���W
	const float PLAYER_INIT_SPEED = 5.0f;//�v���C���[�̏����ړ����x
	const int PLAYER_IMAGE_WIDTH = 64;//�v���C���[�̉摜�̕�
	const int PLAYER_IMAGE_HEIGHT = 64;//�v���C���[�̉摜�̍���
}

Player::Player()
	:GameObject(), hImage_(-1), x_(0), y_(0), speed_(0)
{
	hImage_ = LoadGraph("Assets\\tiny_ship5.png");//�v���C���[�̉摜��ǂݍ���
	x_ = PLAYER_INIT_X;
	y_ = PLAYER_INIT_Y;
	speed_ = PLAYER_INIT_SPEED;
}

Player::~Player()
{
}

void Player::Update()
{
}

void Player::Draw()
{
	DrawExtendGraph(x_, y_, x_ + PLAYER_IMAGE_WIDTH, y_ + PLAYER_IMAGE_HEIGHT, hImage_, TRUE);
}
