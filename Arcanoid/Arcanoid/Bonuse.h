#pragma once

#include "Framework.h"
#include "Const.h"

class Bonuse
{
public:
	Bonuse();
	Bonuse(int x, int y, Sprite* bonuse, int Type);

	void SetSize();

	Vector<int> GetSize();
	Vector<int> GetPosition();
	int GetType();

	virtual void Draw();

	void Move();


private:
	Sprite* _bonuse;
	Vector<int> _pos;
	Vector<int> _size;
	int _type;
	int  _speed;
	
};

