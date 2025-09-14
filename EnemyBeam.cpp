#include "EnemyBeam.h"
#include "DxLib.h"

namespace
{
	const int ENEMY_BEAM_IMAGE_WIDTH = 11;//敵ーの画像の幅
	const int ENEMY_BEAM_IMAGE_HEIGHT = 21;//敵の画像の高さ
	const float ENEMY_BEAM_INIT_SPEED = 250.0f;//弾の初期移動速度
}

EnemyBeam::EnemyBeam()
	:GameObject(),hImage_(-1),pos_({0,0}),speed_(ENEMY_BEAM_INIT_SPEED),
	isFired_(true),
	imageSize_({ ENEMY_BEAM_IMAGE_WIDTH,ENEMY_BEAM_IMAGE_HEIGHT})
{
	hImage_ = LoadGraph("Assets\\ebeams.png");//弾の画像を読みこっむ
	AddGameObject(this);//弾オブジェクトをゲームオブジェクトのインスタンス化
}

EnemyBeam::EnemyBeam(float x, float y)
	:GameObject(), hImage_(-1), pos_({ x,y }), speed_(ENEMY_BEAM_INIT_SPEED),
	isFired_(true),
	imageSize_({ ENEMY_BEAM_IMAGE_WIDTH,ENEMY_BEAM_IMAGE_HEIGHT })
{
	hImage_ = LoadGraph("Assets\\ebeams.png");
	AddGameObject(this);
}

EnemyBeam::EnemyBeam(Point pos_)
	:GameObject(), hImage_(-1), pos_({ pos_.x,pos_.y }), speed_(ENEMY_BEAM_INIT_SPEED),
	isFired_(true),
	imageSize_({ ENEMY_BEAM_IMAGE_WIDTH,ENEMY_BEAM_IMAGE_HEIGHT })
{
	hImage_ = LoadGraph("Assets\\ebeams.png");

	AddGameObject(this);
}

EnemyBeam::~EnemyBeam()
{
	if (hImage_ != -1)
	{
		DeleteGraph(hImage_);
	}
	hImage_ = -1;//
}

void EnemyBeam::Update()
{
	float dt = GetDeltaTime();
	pos_.y = pos_.y + speed_ * dt;//弾の移動
	if (pos_.y > WIN_HEIGHT)
	{
		isFired_ = false;//画面外に出たら弾を準備状態にする
		SetAlive(false);//ゲームオブジェクトを非アクティブにする
	}
}

void EnemyBeam::Draw()
{
	if (isFired_)
	{
		DrawExtendGraphF(pos_.x, pos_.y, pos_.x + imageSize_.x, pos_.y + imageSize_.y, hImage_, FALSE);
	}
}
