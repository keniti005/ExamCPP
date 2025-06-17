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
	const int BULLET_IMAGE_MARGIN = 17;//弾の画像のマージン
	const float BULLET_INTERVAL = 0.5f;//弾の発射間隔
	const int PLAYER_BULLET_NUM = 5;//プレイヤーが同時に発射できる弾の数
}


Player::Player()
	:GameObject(), hImage_(-1), x_(0), y_(0), speed_(0),imageSize_({ PLAYER_IMAGE_WIDTH ,PLAYER_IMAGE_HEIGHT })
{
	hImage_ = LoadGraph("Assets\\tiny_ship5.png");//プレイヤーの画像を読み込む
	x_ = PLAYER_INIT_X;
	y_ = PLAYER_INIT_Y;
	speed_ = PLAYER_INIT_SPEED;
	for (int i = 0;i < PLAYER_BULLET_NUM;i++)
	{
		bullets_.push_back(new Bullet());//弾のベクターを初期化
	}

	assert(hImage_ > 0);
	AddGameObject(this);
}

Player::~Player()
{
	if (hImage_ != -1)
	{
		DeleteGraph(hImage_);//画像のハンドル解放
	}
}

void Player::Update()
{
	Point nextP = { x_,y_ };
	float dt = GetDeltaTime();//フレーム間の時間差を取得
	if (Input::IsKeepKeyDown(KEY_INPUT_LEFT))
	{
		nextP.x = x_ - speed_ * dt;//左に移動
	}
	if (Input::IsKeepKeyDown(KEY_INPUT_RIGHT))
	{
		nextP.x = x_ + speed_ * dt;//右に移動
	}

	if (nextP.x >= 0 && nextP.x + PLAYER_IMAGE_WIDTH <= WIN_WIDTH)
	{
		x_ = nextP.x;
		y_ = nextP.y;
	}

	static float bulletTimer = 0.0f;//弾のタイマー
	if (bulletTimer > 0.0f)
	{
		bulletTimer -= dt;//タイマー減少
	}

	if (Input::IsKeyDown(KEY_INPUT_SPACE))
	{
		if (bulletTimer <= 0.0f)
		{
			Shoot();//弾を発射
			//new Bullet(x_ + BULLET_IMAGE_MARGIN, y_);//弾を発射
			bulletTimer = BULLET_INTERVAL;//弾の発射感覚をリセット
		}
	}
}

void Player::Draw()
{
	//プレイヤーの画像を描画
	DrawExtendGraphF(x_, y_, x_ + PLAYER_IMAGE_WIDTH, y_ + PLAYER_IMAGE_HEIGHT, hImage_, TRUE);
}

//弾を撃つ関数
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
		bit->SetFired(true);//弾を発射状態にする
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
