#include "Enemy.h"
#include "DxLib.h"
#include "Effect.h"
#include <string>
#include <assert.h>

namespace
{
const int ENEMY_IMAGE_WIDTH = 48;//敵ーの画像の幅
const int ENEMY_IMAGE_HEIGHT = 48;//敵の画像の高さ
const int PLAYER_BASE_MARGIN = 32;//敵の基準マージン
const float ENEMY_INIT_X = 100;//敵の初期X座標
const float ENEMY_INIT_Y = 100;//敵の初期Y座標
const float ENEMY_INIT_SPEED = 100.0f;//敵の初期移動速度
const float ENEMY_MOVE_TIME = { 5.0f };

}

Enemy::Enemy()
	:GameObject(), hImage_(-1), x_(0), y_(0), speed_(0), imageSize_({ ENEMY_IMAGE_WIDTH ,ENEMY_IMAGE_HEIGHT }),moveTimer_(ENEMY_MOVE_TIME)
{
	hImage_ = LoadGraph("Assets\\tiny_ship10.png");
	assert(hImage_ > 0);
	x_ = ENEMY_INIT_X;//初期座標
	y_ = ENEMY_INIT_Y;//初期座標
	speed_ = ENEMY_INIT_SPEED;//移動速度
}

Enemy::Enemy(int id, ETYPE type)
	:GameObject(), hImage_(-1), x_(0), y_(0), speed_(0), ID_(id), type_(type), imageSize_({ ENEMY_IMAGE_WIDTH ,ENEMY_IMAGE_HEIGHT }), moveTimer_(ENEMY_MOVE_TIME)
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
	x_ = ENEMY_INIT_X;//初期座標
	y_ = ENEMY_INIT_Y;//初期座標
	speed_ = ENEMY_INIT_SPEED;//移動速度
	//初期化をする必要がある
	//ID_ = ;
	//type_ = ;
	AddGameObject(this);
}

Enemy::~Enemy()
{
	new Effect({ x_,y_ });
	if (hImage_ != -1)
	{
		DeleteGraph(hImage_);//画像のハンドル解放
	}
}

void Enemy::Update()
{
	//float dt = GetDeltaTime();
	//moveTimer_ = moveTimer_ - dt;
	//if (moveTimer_ < 0)
	//{
	//	x_ = x_ - 0.5;
	//}
	//else
	//{
	//	x_ = x_ + 0.5f;
	//}

	x_ = x_ + 0.5f;
	y_ = y_;
}

void Enemy::Draw()
{
	DrawExtendGraphF(x_, y_, x_ + ENEMY_IMAGE_WIDTH, y_ + ENEMY_IMAGE_HEIGHT, hImage_, TRUE);
}
