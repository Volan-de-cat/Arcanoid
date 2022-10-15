#include "Ball.h"
#include "Const.h"
#include <cmath>
#include <iostream>

Ball::Ball()
{
}

void Ball::SetSize()
{
	_size.x = ballsizex;
	_size.y = ballsizey;
	setSpriteSize(_ball, _size.x, _size.y);
}

void Ball::Init()
{
	_ball = createSprite(ballPath.c_str());
	SetSize();
}


void Ball::SetDirection(Vector<double> direction)
{
	if (!caught)
	{
		_direction.x = direction.x;
		_direction.y = direction.y;
	}
}

void Ball::Update(Board board)
{
	if(!caught)
	{
		Vector<int> boardsize = board.GetSize();
		Vector<int> boardpos = board.GetPosition();
		_pos.x = boardpos.x + ((boardsize.x - _size.x )/ 2);
		_pos.y = boardpos.y - _size.y;
	}
	if(caught) 
	{
		_pos.x += _direction.x * _speed;
		_pos.y += _direction.y * _speed;
	}
}

void Ball::Active()
{
	if (!caught)
	{
		caught = true;
	}
}

void Ball::Deactivate()
{
	caught = false;
}

void Ball::Draw()
{ 
	drawSprite(_ball, round(_pos.x), round(_pos.y));
}

void Ball::reverseDirectionX() {
	_direction.x *= -1;
}

void Ball::reverseDirectionY() {
	_direction.y *= -1;
}

Vector<double> Ball::getPosition()
{
	return _pos;
}

Vector<double> Ball::getVelocity()
{
	return { _direction.x * _speed,_direction.y * _speed };
}

Vector<int> Ball::getSize()
{
	return _size;
}

void Ball::setSpeed(double speed)
{
	_speed = speed;
}

void Ball::Shiled(bool isActive)
{
	_isShielded = isActive;
}

bool Ball::isActive()
{
	return _isShielded;
}
