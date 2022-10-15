#pragma once

#include "Framework.h"
#include "Const.h"

#include <list>;


class Board
{
public:
	Board();

	void ControlSize();

	void Init();

	virtual void StartPos();

	Vector<int> GetSize();
	Vector<int> GetPosition();

	void Draw();

	bool IsCollideRightX() const;
	bool IsCollideLeftX() const;

	void Move();

	void StartMoveRight();
	void StartMoveLeft();

	void EndMoveRight();
	void EndMoveLeft();

	void ActiveSizeUp();

	void CheckSizeUp();

	void DeactiveSizeUp(std::list<unsigned int>::iterator end);

	void ActiveSizeDown();

	void CheckSizeDown();

	void DeactiveSizeDown(std::list<unsigned int>::iterator end);

	void reset();

private:
	Sprite* _board;
	Vector<int> _pos;
	int Direction ;
	Vector<int> _size;
	bool caught{ false };
	int counterUp;
	int counterDown;
	int Up;
	int Down;
	std::list<unsigned int> TimeUp;
	std::list<unsigned int> TimeDown;
};
