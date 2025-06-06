#include "Stage.h"
#include "DxLib.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

namespace
{
	const int ENEMY_COL_SIZE = 10;//�G�̗�
	const int ENEMY_ROW_SIZE = 7;//�G�̍s��
	const int ENEMY_NUM = ENEMY_COL_SIZE * ENEMY_ROW_SIZE;//�G�̐�
	const float ENEMY_ALIGN_X = 55.0f;//�G����ׂ镝
	const float ENEMY_ALIGN_Y = 50.0f;//�G����ׂ鍂��
	const int ENEMY_LEFT_MARGIN = WIN_WIDTH - (ENEMY_ALIGN_X * ENEMY_ALIGN_Y) / 2;
	const int ENEMY_TOP_MARGIN = 75;
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
		int col = i % ENEMY_COL_SIZE;//��
		int row = i / ENEMY_COL_SIZE;//�s
		ETYPE enemyType[ENEMY_ROW_SIZE] = { BOSS,KNIGHT,MID,ZAKO,ZAKO,ZAKO };//�G�̎��
		enemy_[i] = new Enemy(i, enemyType[row]);//�G�I�u�W�F�N�g�̐���

		enemy_[i]->SetPos(col * ENEMY_ALIGN_X + ENEMY_LEFT_MARGIN,row * ENEMY_ALIGN_Y + ENEMY_TOP_MARGIN);//�G�̏����ʒu�ݒ�

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
