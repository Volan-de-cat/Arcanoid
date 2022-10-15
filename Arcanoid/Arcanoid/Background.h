#pragma once

#include "Framework.h"
#include "Const.h"

class Background
{
public:
	Background();

	void Init();
	void Draw();

private:
	Sprite* _background;
	Vector<int> _pos;
};

