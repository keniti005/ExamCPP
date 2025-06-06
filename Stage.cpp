#include "Stage.h"
#include "DxLib.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

namespace
{
	const int ENEMY_NUM = 10*7;//敵の数
	const int ENEMY_COL_SIZE = 10;//敵の列数
	const int ENEMY_ROW_SIZE = 7;//敵の行数
	bool IntersectRect(const Rect &_a,const Rect &_b)
	{
		bool xOverlap = (_a.x < _b.x + _b.width) && (_b.x < _a.x + _a.width);

		bool yOverlap = (_a.y < _b.y + _b.height) && (_b.y < _a.y + _a.height);

		return xOverlap && yOverlap;
	}
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
	hBackgraound = LoadGraph("Assets\\bg.png");
}

Stage::~Stage()
{
}

void Stage::Update()
{
	std::vector<Bullet*> bullets = player_->GetAllBullets();
	for (auto& e : enemy_)
	{
		for (auto& b : bullets)
		{
			if (b->IsFired() && e->IsAlive())
			{
				if (IntersectRect(e->GetRect(), b->GetRect()))
				{
					if (b->IsFired())
					{
						b->SetFired(false);
					}
					if (e->IsAlive())
					{
						e->SetAlive(false);
					}

				}
			}
		}
	}
}

void Stage::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	DrawExtendGraph(0, 0, WIN_WIDTH, WIN_HEIGHT, hBackgraound,FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
