#include "Stage.h"
#include "Player.h"
#include "Enemy.h"

namespace
{
	const int ENEMY_NUM = 10*7;//敵の数
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
		int col = i % ENEMY_COL_SIZE;//列
		int row = i / ENEMY_COL_SIZE;//行
		ETYPE enemyType[ENEMY_ROW_SIZE] = { BOSS,KNIGHT,MID,ZAKO,ZAKO,ZAKO };//敵の種類
		enemy_[i] = new Enemy(i, enemyType[row]);//敵オブジェクトの生成

		enemy_[i]->SetPos(col * 55.0f,row * 50.0f);//敵の初期位置設定

	}
}

Stage::~Stage()
{
}

void Stage::Update()
{
}

void Stage::Draw()
{
}
