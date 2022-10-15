#pragma once

#include "Framework.h"
#include "Const.h"
#include "Board.h"



class Ball
{
public:
	Ball();

	void SetSize();
	void Init();
	void SetDirection(Vector<double> direction);
	virtual void Update(Board board);

	void Active(); 
	void Deactivate();
	
	void Draw();

	void reverseDirectionX();
	void reverseDirectionY();

	Vector<double> getPosition();
	Vector<int> getSize();
	Vector<double> getVelocity();

	void setSpeed(double speed);

	void Shiled(bool isActive);
	bool isActive();

private:
	Sprite* _ball;
	Vector<double> _pos{ 0.0,0.0 };
	Vector<double> _direction{ 1.0,1.0 };
	Vector<int> _size{ 10,10 };
	double _speed{ 1.0 };
	bool caught{ false };
	bool _isShielded{ false };
};

