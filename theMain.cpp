#include "DxLib.h"
#include "globals.h"
#include "Input.h"
#include <vector>
#include "Stage.h"

namespace
{
	const int BGCOLOR[3] = { 0, 0, 0 };//背景色
	int crrTime;
	int prevTime;
	int scene;
}

enum SCENE
{
	TITLE = 0, 
	PLAY, 
	OVER, 
	MAX_SCENE
};

std::vector<GameObject*> gameObjects;//ゲームオブジェクトのベクター
std::vector<GameObject*> newObjects;


float gDeltaTime = 0.0f;//フレーム間の時間差

void DxInit()
{
	ChangeWindowMode(true);
	SetWindowSizeChangeEnableFlag(false, false);
	SetMainWindowText("TITLE");
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);
	SetWindowSizeExtendRate(1.0);
	SetBackgroundColor(BGCOLOR[0],BGCOLOR[1],BGCOLOR[2]);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		DxLib_End();
	}

	SetDrawScreen(DX_SCREEN_BACK);
}

void MyGame()
{

	DrawFormatString(100, 100, GetColor(0, 0, 0), "ウィンドウのテスト");
	static int timer = 0;
	timer++;
	DrawFormatString(100, 150, GetColor(0, 0, 0), "%010d", timer);
}

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	DxInit();
	crrTime = GetNowCount();
	prevTime = GetNowCount();

	//Player* player = new Player();
	//Enemy* enemy = new Enemy[ENEMY_NUM];
	//for (int i = 0;i < ENEMY_NUM;i++)
	//{
	//	enemy[i].SetPos(100 + i * 50, 100);
	//}
	//std::vector<Enemy> enemy(ENEMY_NUM);
	//for (int i = 0;i < ENEMY_NUM;i++)
	//{
	//	enemy[i].SetPos(100 + i * 50, 100);
	//}
	//int i = 0;
	//for (auto& e : enemy)
	//{
	//	e.SetPos(100 + i * 50, 100);
	//	i++;
	//}

//	Scene* scene = new Scene();

	while (true)
	{
		ClearDrawScreen();
		Input::KeyStateUpdate();

		crrTime = GetNowCount();//現在の時間を取得
		//前回の時間差との差分を計算
		float deltaTime = (crrTime - prevTime) / 1000.0f;
		gDeltaTime = deltaTime;

		switch (scene)
		{
		case TITLE:
			DrawString(100, 400, "PLAY Push [P] Key",GetColor(255,255,255));
			if (Input::IsKeyDown(KEY_INPUT_P))
			{
				Stage* stage = new Stage();//ステージオブジェクトの生成
				scene = PLAY;
			}
			break;

		case PLAY:
			//ここにやりたい処理を書く
			if (newObjects.size() > 0)
			{
				for (auto& obj : newObjects)
				{
					gameObjects.push_back(obj);//新しいゲームオブジェクトを追加
				}
				newObjects.clear();//新しいオブジェクトのベクタークリア
			}

			//gameObjectsの更新
			for (auto& obj : gameObjects)
			{
				obj->Update();
			}
			//gameObjectsの描画
			for (auto& obj : gameObjects)
			{
				obj->Draw();
			}

			for (auto it = gameObjects.begin();it != gameObjects.end();)
			{
				if (!(*it)->IsAlive())
				{
					delete* it;//ゲームオブジェクトを削除
					it = gameObjects.erase(it);
				}
				else
				{
					it++;//次の要素へ
				}
			}
			if (Input::IsKeyDown(KEY_INPUT_T))
			{
				scene = OVER;
			}
			break;
		case OVER:
			DrawString(100, 400, "TITLE Push [T] Key", GetColor(255, 255, 255));
			if (Input::IsKeyDown(KEY_INPUT_T))
			{
				scene = TITLE;
				newObjects.clear();
				gameObjects.clear();
			}
			break;
		}

		//for (auto& elm : enemy)
		//{
		//	elm.Update();
		//	elm.Draw();
		//}
		//for (int i = 0;i < 10;i++)
		//{
		//	(enemy + i)->Update();
		//	(enemy + i)->Draw();
		//	//enemy[i].Update();
		//	//enemy[i].Draw();
		//}

		ScreenFlip();
		WaitTimer(16);

		prevTime = crrTime;//現在の時間を前回の時間として保存

		if (ProcessMessage() == -1)
			break;
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			break;
	}

	DxLib_End();
	return 0;
}