#include "Scene.h"
#include "DxLib.h"
#include "Input.h"

Scene::Scene()
	:GameObject(),scene_(TITLE), stage_(nullptr)
{

	AddGameObject(this);
}

Scene::~Scene()
{
}

void Scene::Update()
{
	switch (scene_)
	{
	case TITLE:
		if (Input::IsKeyDown(KEY_INPUT_T))
		{
			scene_ = PLAY;
			stage_ = new Stage();
		}
		break;
	case PLAY:
		if (Input::IsKeyDown(KEY_INPUT_T))
		{
			scene_ = OVER;
		}
		break;
	case OVER:
		if (Input::IsKeyDown(KEY_INPUT_T))
		{
			scene_ = TITLE;
		}
		break;
	default:
		break;
	}

}

void Scene::Draw()
{
	if (scene_ == TITLE)
	{
		DrawString(0, 0, "TITLE SCENE", GetColor(255, 255, 255));
	}
	else if (scene_ == OVER)
	{
		DrawString(0, 0, "OVER SCENE", GetColor(255, 255, 255));
	}
}
