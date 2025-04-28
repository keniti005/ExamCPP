#pragma once
#include "GameObject.h"
class Enemy :
    public GameObject
{
    Enemy();
    ~Enemy();
    void Update() override;
    void Draw() override;
};

