

#include "Game.h"

#include "Const.h"

#include <cmath>
#include <cstdlib>
#include <time.h>

Game::Game()
{
}

void Game::PreInit(int& width, int& height, bool& fullscreen)
{
	width = SCREEN_WIDTH;
	height = SCREEN_HEIGHT;
	fullscreen = false;
}

bool Game::Init()
{
	background.Init();
	board.Init();
	ball.Init();
	factoryBrick.Init();
	factoryBonuse.Init();
	CreateBricks();
	return true;
}

void Game::Close()
{
}

bool Game::Tick()
{
	background.Draw();
	ball.Draw();
	board.Draw();
	for (Brick brick : bricks)
	{
		brick.Draw();
	}
	for (Bonuse& bonuse : bonuses)
	{
		bonuse.Draw();
	}
	if (!_end)
	{
		ball.Update(board);
		update();
		DestroyBonuse();
		board.CheckSizeUp();
		board.CheckSizeDown();
		board.Move();
		for (Bonuse& bonuse : bonuses)
		{
			bonuse.Move();
		}
	}
	return false;
}

void Game::onMouseMove(int x, int y, int xrelative, int yrelative)
{
	ball.SetDirection(norm(x,y));
}

void Game::onMouseButtonClick(FRMouseButton button, bool isReleased)
{
	if (button == FRMouseButton::LEFT)
	{
		ball.Active();
	}
	if (button == FRMouseButton::RIGHT)
	{
		if (score >= 20 && !_end)
		{
			score -= 20;
			int ran = rand() % 3;
			switch (ran)
			{
			case 0:
			{
				board.ActiveSizeDown();
				break;
			}
			case 1:
			{
				board.ActiveSizeUp();
				break;
			}
			case 2:
			{
				ball.Shiled(true);
				break;
			}
			default:
				break;
			}
		}
		else if (_end)
		{
			reset();
		}
	}
}

void Game::onKeyPressed(FRKey k)
{
	if (k == FRKey::RIGHT)
	{
		board.StartMoveRight();
	}
	if (k == FRKey::LEFT)
	{
		board.StartMoveLeft();
	}
}

void Game::onKeyReleased(FRKey k)
{
	if (k == FRKey::RIGHT)
	{
		board.EndMoveRight();
	}
	if (k == FRKey::LEFT)
	{
		board.EndMoveLeft();
	}
}

const char* Game::GetTitle()
{
	return "Arcanoid";
}

void Game::CreateBricks()
{
	unsigned x = 0;
	unsigned y = 0;
	time_t seconds;
	time(&seconds);

	srand((unsigned int)seconds);

	int ran = 0;


	for (int y = 0; y < SCREEN_HEIGHT/4; y++) 
	{
		for (int x = 1; x < SCREEN_WIDTH; x++) 
		{
			ran = rand() % 100 + 1;
			if (ran >= 50) 
			{
				Brick brick = factoryBrick.CreateBrick(x, y);
				addCollidableBrick(brick);
			}
			x += bricksizex;
		}
		y += bricksizey;
	}
}

void Game::CreateBonuse(std::list<Brick>::iterator brick)
{
	Vector<int> pos = brick->GetPosition();
	Vector<int> size = brick->GetSize();
	int x = pos.x + (size.x / 2);
	int y = pos.y + (size.y / 2);
	time_t seconds;
	time(&seconds);

	srand((unsigned int)seconds);

	int ran = 0;

	ran = rand() % 100 + 1;
	if (ran >= 90)
	{
		Bonuse bonuse = factoryBonuse.CreateBonuse(x, y);
		addCollidableBonuse(bonuse);
	}
}

void Game::DestroyBonuse()
{
	std::list<Bonuse>::iterator destroyable;
	bool destroy = false;

	for (std::list<Bonuse>::iterator bonuse = bonuses.begin(); bonuse != bonuses.end(); bonuse++)
	{
		if (observer.IsCollideY(bonuse))
		{
			destroyable = bonuse;
			destroy = true;
		}	
		if (observer.isPaddleCollide(bonuse, board))
		{
			destroyable = bonuse;
			destroy = true;
			int bonusetype = bonuse->GetType();
			switch (bonusetype)
			{
			case 0:
			{
				board.ActiveSizeDown();
				break;
			}
			case 1:
			{
				board.ActiveSizeUp();
				break;
			}
			case 2:
			{
				ball.Shiled(true);
				break;
			}
			default:
				break;
			}

		}
	}
	if (destroy)
	{
		bonuses.erase(destroyable);
	}
}

void Game::addCollidableBrick(Brick brick) {
	bricks.push_back(brick);
}

void Game::addCollidableBonuse(Bonuse bonuse)
{
	bonuses.push_back(bonuse);
}

void Game::reset()
{
	score = 0;
	_end = false;
	bricks.clear();
	bonuses.clear();
	CreateBricks();
	board.reset();
	ball.Deactivate();
}

void Game::update()
{
	std::list<Brick>::iterator destroyable;
	bool destroyX = false;
	bool destroyY = false;
	bool destroyXY = false;

	for (std::list<Brick>::iterator brick = bricks.begin(); brick != bricks.end(); brick++)
	{
		if (observer.brickCollide(brick, ball))
		{
			if (observer.brickCollideY(brick, ball) && observer.brickCollideX(brick, ball))
			{
				CreateBonuse(brick);
				destroyable = brick;
				destroyXY = true;
				score += 5;
			}
			else if (observer.brickCollideX(brick, ball))
			{
				CreateBonuse(brick);
				destroyable = brick;
				destroyX = true;
				score += 5;
			}
			else if (observer.brickCollideY(brick, ball))
			{
				CreateBonuse(brick);
				destroyable = brick;
				destroyY = true;
				score += 5;
			}
		}
	}
	if (destroyXY)
	{
		ball.reverseDirectionX();
		ball.reverseDirectionY();
		bricks.erase(destroyable);
	}
	if (destroyY)
	{
		ball.reverseDirectionY();
		bricks.erase(destroyable);
	}
	if(destroyX)
	{
		ball.reverseDirectionX();
		bricks.erase(destroyable);
	}
	if (observer.isPaddleCollide(ball, board))
	{
		if (!bricks.empty())
		{
			ball.reverseDirectionY();
		}
		else
		{
			_end = true;
		}
	}
	else
	{
		if (observer.IsCollideX(ball))
		{
			ball.reverseDirectionX();
		}
		if (observer.IsCollideUpY(ball))
		{
			ball.reverseDirectionY();
		}
		if (observer.IsCollideDownY(ball))
		{
			if (!ball.isActive())
			{
				_end = true;
			}
			else
			{
				ball.Shiled(false);
				ball.reverseDirectionY();
			}
		}
	}
	if (observer.speedUpZone(ball))
	{
		ball.setSpeed(1.5);
	}
	if (observer.speedNormZone(ball))
	{
		ball.setSpeed(1.0);
	}
	if (observer.speedDownZone(ball))
	{
		ball.setSpeed(0.5);
	}
}

Vector<double> Game::norm(int x, int y)
{
	Vector<double> ballpos = ball.getPosition();
	return { (1.0 * (x - ballpos.x) / sqrt(((x - ballpos.x) * (x - ballpos.x)) + ((y - ballpos.y) * (y - ballpos.y)))), (1.0 * (y - ballpos.y) / sqrt(((x - ballpos.x) * (x - ballpos.x)) + ((y - ballpos.y) * (y - ballpos.y)))) };
}
