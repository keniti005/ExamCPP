#pragma once
#include "GameObject.h"
#include "globals.h"

class Effect :
    public GameObject
{
public:
    Effect();
    ~Effect();
    void Update()override;
    void Draw()override;
private:
    int hImage_;
    int x_, y_;
    float animTimer_;
};

