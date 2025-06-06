#include "Effect.h"
#include "DxLib.h"
#include <string>

namespace
{
	const float ANIME_TIME = { 1.0f };//ƒAƒjƒ‚Ì‘ŠÔ‚Ì‰Šú’l
	const int EFFECT_IMAGE_SIZE = 48;
	const std::string EFFECT_PATH = "Assets\\explosion.png";
	const int MAX_FRAME = 9;//‰æ–Ê‚Ì•ªŠ„”
	const int DIV_NUM = 3;//‰æ‘œ‚Ì•ªŠ„”
	const float FRAME_TIME = ANIME_TIME / MAX_FRAME;
}

Effect::Effect(Point _pos)
	:GameObject(), pos_({ _pos.x,_pos.y }), animTimer_(ANIME_TIME), hImage_(std::vector<int>(MAX_FRAME, -1)),
	frameTimer_(FRAME_TIME), frame_(0)
{
	//hImage_ = LoadGraph(EFFECT_PATH.c_str());
	LoadDivGraph(EFFECT_PATH.c_str(), MAX_FRAME, DIV_NUM, DIV_NUM, EFFECT_IMAGE_SIZE, EFFECT_IMAGE_SIZE, hImage_.data());
	AddGameObject(this);
}

Effect::~Effect()
{
	for (auto& itr : hImage_)
	{
		DeleteGraph(itr);
	}
	hImage_.clear();
}

void Effect::Update()
{
	float dt = GetDeltaTime();
	animTimer_ = animTimer_ = dt;
	if (animTimer_ < 0)
	{
		this->isAlive_ = false;
	}
	
	frameTimer_ = frameTimer_ - dt;
	if (frameTimer_ < 0)
	{
		frame_++;
		frameTimer_ = FRAME_TIME - frameTimer_;
	}
}

void Effect::Draw()
{
 	DrawExtendGraph(pos_.x, pos_.y, pos_.x + EFFECT_IMAGE_SIZE, pos_.y + EFFECT_IMAGE_SIZE, hImage_[frame_], TRUE);
}
