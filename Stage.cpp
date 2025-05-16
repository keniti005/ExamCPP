#include "Stage.h"
#include "Player.h"
#include "Enemy.h"

namespace
{
	const int ENEMY_NUM = 10*7;//“G‚Ì”
	const int ENEMY_COL_SIZE = 10;
	const int ENEMY_ROW_SIZE = 7;
}

Stage::Stage()
	:GameObject(), player_(nullptr)
{
	AddGameObject(this);
	player_ = new Player();
	enemy_ = std::vector<Enemy*>(ENEMY_NUM);
	for (int i = 0;i < ENEMY_NUM; i++)
	{
		int col = i % ENEMY_COL_SIZE;//—ñ
		int row = i / ENEMY_COL_SIZE;//s
		ETYPE enemyType[ENEMY_ROW_SIZE] = { BOSS,KNIGHT,MID,ZAKO,ZAKO,ZAKO };//“G‚Ìí—Ş
		enemy_[i] = new Enemy(i, enemyType[row]);//“GƒIƒuƒWƒFƒNƒg‚Ì¶¬

		enemy_[i]->SetPos(col * 55,row * 50);//“G‚Ì‰ŠúˆÊ’uİ’è

	}
}

Stage::~Stage()
{
}

void Stage::Update()
{
	player_->Update();
	for (auto& elm : enemy_)
	{
		elm->Update();
	}
}

void Stage::Draw()
{
	player_->Draw();
	for (auto& elm : enemy_)
	{
		elm->Draw();//“G‚Ì•`‰æ
	}
}
