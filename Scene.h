#pragma once
#include "GameObject.h"
#include "Stage.h"
#include "globals.h"

enum SCENE
{
    TITLE,PLAY,OVER,MAX_SCENE
};

class Scene :
    public GameObject
{
public:
    Scene();
    ~Scene();
    void Update()override;
    void Draw()override;
protected:
private:
    SCENE scene_;
    Stage* stage_;
};

