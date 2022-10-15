#pragma once

#include "Framework.h"
#include "Const.h"

class Brick
{
public:
	Brick();
	Brick(int x, int y, Sprite* brick);
	void SetSize();
	Vector<int> GetSize();
	Vector<int> GetPosition();
	virtual void Draw();

private:
	Sprite* _brick;
	Vector<int> _pos;
	Vector<int> _size;
};

