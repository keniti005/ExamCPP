#include "Stage.h"
#include "DxLib.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "EnemyBeam.h"

namespace
{
	const int ENEMY_COL_SIZE = 10;//ìGÇÃóÒêî
	const int ENEMY_ROW_SIZE = 7;//ìGÇÃçsêî
	const int ENEMY_NUM = ENEMY_COL_SIZE * ENEMY_ROW_SIZE;//ìGÇÃêî
	const float ENEMY_ALIGN_X = 55.0f;//ìGÇï¿Ç◊ÇÈïù
	const float ENEMY_ALIGN_Y = 50.0f;//ìGÇï¿Ç◊ÇÈçÇÇ≥
	const int ENEMY_LEFT_MARGIN = (WIN_WIDTH - (ENEMY_ALIGN_X * ENEMY_COL_SIZE)) / 2;
	const int ENEMY_TOP_MARGIN = 75;
	bool IntersectRect(const Rect &_a,const Rect &_b)
	{
		bool xOverlap = (_a.x < _b.x + _b.width) && (_b.x < _a.x + _a.width);

		bool yOverlap = (_a.y < _b.y + _b.height) && (_b.y < _a.y + _a.height);

		return xOverlap && yOverlap;
	}
}

Stage::Stage()
	:GameObject(), player_(nullptr), enemyBeam_(nullptr)
{
	AddGameObject(this);
	player_ = new Player();
	enemyBeam_ = new Enemy();
	enemy_ = std::vector<Enemy*>(ENEMY_NUM);
	for (int i = 0;i < ENEMY_NUM; i++)
	{
		int col = i % ENEMY_COL_SIZE;//óÒ
		int row = i / ENEMY_COL_SIZE;//çs
		ETYPE enemyType[ENEMY_ROW_SIZE] = { BOSS,KNIGHT,MID,ZAKO,ZAKO,ZAKO };//ìGÇÃéÌóﬁ
		enemy_[i] = new Enemy(i, enemyType[row]);//ìGÉIÉuÉWÉFÉNÉgÇÃê∂ê¨
		enemy_[i]->SetMaxMovex(ENEMY_LEFT_MARGIN);
		enemy_[i]->SetPos(col * ENEMY_ALIGN_X + ENEMY_LEFT_MARGIN,row * ENEMY_ALIGN_Y + ENEMY_TOP_MARGIN);//ìGÇÃèâä˙à íuê›íË
		enemy_[i]->SetXorigin(col * ENEMY_ALIGN_X + ENEMY_LEFT_MARGIN);
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
	std::vector<EnemyBeam*> enemyBeams = enemyBeam_->GetAllEnemyBeams();
	for (auto& b : enemyBeams)
	{ 
		if (b->IsFired() && player_->IsAlive())
		{
			if (IntersectRect(player_->GetRect(), b->GetRect()))
			{
				if (b->IsFired())
				{
					b->SetFired(false);
				}
				if (player_->IsAlive())
				{
					player_->SetAlive(false);
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
