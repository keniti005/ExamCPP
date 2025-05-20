#include "Player.h"
#include "DxLib.h"
#include "globals.h"
#include "Input.h"
#include "Bullet.h"
#include <assert.h>

namespace
{
	const int PLAYER_IMAGE_WIDTH = 48;//プレイヤーの画像の幅
	const int PLAYER_IMAGE_HEIGHT = 48;//プレイヤーの画像の高さ
	const int PLAYER_BASE_MARGIN = 32;//プレイヤーの基準マージン
	const float PLAYER_INIT_X = WIN_WIDTH / 2 - PLAYER_IMAGE_WIDTH;//プレイヤーの初期X座標
	const float PLAYER_INIT_Y = WIN_HEIGHT - PLAYER_IMAGE_HEIGHT - PLAYER_BASE_MARGIN;//プレイヤーの初期Y座標
	const float PLAYER_INIT_SPEED = 200.0f;//プレイヤーの初期移動速度
}

Player::Player()
	:GameObject(), hImage_(-1), x_(0), y_(0), speed_(0)
{
	hImage_ = LoadGraph("Assets\\tiny_ship5.png");//プレイヤーの画像を読み込む
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
	float dt = GetDeltaTime();//フレーム間の時間差を取得
	if (Input::IsKeepKeyDown(KEY_INPUT_LEFT))
	{
		x_ = x_ - speed_ * dt;//左に移動
	}
	if (Input::IsKeepKeyDown(KEY_INPUT_RIGHT))
	{
		x_ = x_ + speed_ * dt;//右に移動
	}

	if (Input::IsKeyDown(KEY_INPUT_SPACE))
	{
		new Bullet(x_,y_);//弾を発射
	}
}

void Player::Draw()
{
	//プレイヤーの画像を描画
	DrawExtendGraph(x_, y_, x_ + PLAYER_IMAGE_WIDTH, y_ + PLAYER_IMAGE_HEIGHT, hImage_, TRUE);
}
