#include "Brick.h"


Brick::Brick()
{
}

Brick::Brick(int x, int y, Sprite* brick)
	:_pos ({x, y})
{
	_brick = brick;
	SetSize();
}

void Brick::SetSize()
{
	_size.x = bricksizex;
	_size.y = bricksizey;
}

Vector<int> Brick::GetSize()
{
	return _size;
}

Vector<int> Brick::GetPosition()
{
	return _pos;
}

void Brick::Draw()
{
	drawSprite(_brick, _pos.x, _pos.y);
}