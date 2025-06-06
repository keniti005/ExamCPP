#pragma once
#include "GameObject.h"
#include "globals.h"
#include <vector>

class Effect :
    public GameObject
{
public:
    Effect(Point _pos);
    ~Effect();
    void Update()override;
    void Draw()override;
private:
    std::vector<int> hImage_;
    Point pos_;
    int x_, y_;
    float animTimer_;
    int frameTimer_;
    int frame_;
};

