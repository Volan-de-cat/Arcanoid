#include "Board.h"

Board::Board()
{
}

void Board::ControlSize()
{
	setSpriteSize(_board, _size.x + Up - Down, _size.y);
}

void Board::Init()
{
	_size.x = boardsizex;
	_size.y = boardsizey;
	Up = 0;
	Down = 0;
	Direction = 0;
	_pos.x = 0;
	counterUp = 0;
	counterDown = 0;
	_board = createSprite(boardPath.c_str());
	ControlSize();
	StartPos();
}

void Board::StartPos()
{
	_pos.y = SCREEN_HEIGHT - 2 * _size.y;
}


Vector<int> Board::GetSize()
{
	return { _size.x + Up - Down, _size.y };
}

Vector<int> Board::GetPosition()
{
	return _pos;
}

void Board::Draw()
{
	drawSprite(_board, _pos.x, _pos.y);
}

bool Board::IsCollideRightX() const
{
	if ((_pos.x + _size.x + Up - Down) <= SCREEN_WIDTH)
	{
		return true;
	}
	return false;
}

bool Board::IsCollideLeftX() const
{
	if (_pos.x >= 0)
	{
		return true;
	}
	return false;
}

void Board::Move()
{
	if(caught)
	{
		if (IsCollideRightX() && Direction == 2)
		{
			_pos.x += Direction;
		}
		if (IsCollideLeftX() && Direction == -2)
		{
			_pos.x += Direction;
		}
	}

}

void Board::StartMoveRight()
{
	caught = true;
	Direction = 2;
}

void Board::StartMoveLeft()
{
	caught = true;
	Direction = -2;
}

void Board::EndMoveRight()
{
	caught = false;
	Direction = 0;
}

void Board::EndMoveLeft()
{
	caught = false;
	Direction = 0;
}

void Board::ActiveSizeUp()
{
	counterUp++;
	TimeUp.push_back(getTickCount());
	if (counterUp <= 4) {
		Up += (boardsizex / 100) * 50;
	}
	ControlSize();
}

void Board::CheckSizeUp()
{
	std::list<unsigned int>::iterator endtime;
	bool finish = false;
	for (std::list<unsigned int>::iterator check = TimeUp.begin(); check != TimeUp.end(); check++)
	{
		if (getTickCount() - *check >= 20000)
		{
			endtime = check;
			finish = true;
		}
	}
	if (finish) 
	{
		DeactiveSizeUp(endtime);
	}
}

void Board::DeactiveSizeUp(std::list<unsigned int>::iterator end)
{
	counterUp--;
	TimeUp.erase(end);
	if (counterUp <= 3) 
	{
		Up -= (boardsizex / 100) * 50;

		ControlSize();
	}
}

void Board::ActiveSizeDown()
{
	counterDown++;
	TimeDown.push_back(getTickCount());

	if (counterDown <= 2) 
	{
		Down += (boardsizex / 100) * 40;
		if (Down > (boardsizex / 100) * 50)
		{
			Down = (boardsizex / 100) * 50;
		}
	}
		ControlSize();
}

void Board::CheckSizeDown()
{
	std::list<unsigned int>::iterator endtime;
	bool finish = false;
	for (std::list<unsigned int>::iterator check = TimeDown.begin(); check != TimeDown.end(); check++)
	{
		if (getTickCount() - *check >= 20000)
		{
			endtime = check;
			finish = true;
		}
	}
	if (finish)
	{
		DeactiveSizeDown(endtime);
	}
}

void Board::DeactiveSizeDown(std::list<unsigned int>::iterator end)
{
	counterDown--;
	TimeDown.erase(end);
	if (counterDown <= 1)
	{
		Down = (counterDown * (boardsizex / 100) * 40);

		ControlSize();

	}
}

void Board::reset()
{
	_pos.x = 0;
	Direction = 0;
	_size.x = boardsizex;
	_size.y = boardsizey;
	caught = false; 
	Up = 0;
	Down = 0;
	counterUp = 0;
	counterDown = 0;
	TimeUp.clear();
	TimeDown.clear();
	ControlSize();
	StartPos();
}
