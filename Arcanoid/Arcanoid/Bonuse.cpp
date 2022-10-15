#include "Bonuse.h"

Bonuse::Bonuse()
{

}

Bonuse::Bonuse(int x, int y, Sprite* bonuse, int Type)
	:_pos({ x, y })
{
		_bonuse = bonuse;
		_type = Type;
		_speed = bonusespeed;
		SetSize();

}

void Bonuse::SetSize()
{
	_size.x = bonusesizex;
	_size.y = bonusesizey;
}

Vector<int> Bonuse::GetSize()
{
	return _size;
}

Vector<int> Bonuse::GetPosition()
{
	return _pos;
}

int Bonuse::GetType()
{
	return _type;
}

void Bonuse::Draw()
{
	drawSprite(_bonuse, _pos.x, _pos.y);
}

void Bonuse::Move()
{
	_pos.y += _speed;
}
