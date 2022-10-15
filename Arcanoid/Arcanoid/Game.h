#pragma once
#include "Framework.h"
#include "Ball.h"
#include "Board.h"
#include "CollisionObserver.h"
#include "Background.h"
#include "Brick.h"
#include "Bonuse.h"
#include "BrickFabric.h"
#include "BonuseFabric.h"

class Game : public Framework
{
public:
	Game();

	virtual void PreInit(int& width, int& height, bool& fullscreen) override;
	virtual bool Init() override;
	virtual void Close() override;

	virtual bool Tick() override;

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) override;
	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) override;

	virtual void onKeyPressed(FRKey k) override;
	virtual void onKeyReleased(FRKey k) override;

	virtual const char* GetTitle() override;


private:
	void CreateBricks();
	void CreateBonuse(std::list<Brick>::iterator brick);

	void DestroyBonuse();

	void addCollidableBrick(Brick brick);
	void addCollidableBonuse(Bonuse bonuse);


	void update();

	Vector<double> norm(int x, int y);

	void reset();

private:
	Ball ball;
	Board board;
	CollisionObserver observer;
	Background background;
	BrickFabric factoryBrick;
	BonuseFabric factoryBonuse;
	std::list<Brick> bricks;
	std::list<Bonuse> bonuses;
	int score{0};
	bool _end {false};
};

