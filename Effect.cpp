#include "Effect.h"
#include "DxLib.h"

namespace
{

}

Effect::Effect()
	:GameObject(),hImage_(-1),x_(0),y_(0),animTimer_(3.0f)
{
	hImage_ = LoadGraph("Assets\\explosion.png");
	AddGameObject(this);
}

Effect::~Effect()
{
	float dt = GetDeltaTime();
	animTimer_ = animTimer_ = dt;
	if (animTimer_ < 0)
	{
		this->isAlive_ = false;
	}
}

void Effect::Update()
{
}

void Effect::Draw()
{
	DrawExtendGraph(x_, y_,x_+48,y_+48, hImage_, FALSE);
}
