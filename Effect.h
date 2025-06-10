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
    float animTimer_;
    float frameTimer_;
    int frame_;
};

