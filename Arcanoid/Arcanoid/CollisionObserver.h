#pragma once

#include <memory>
#include <list>

class Ball;
class Brick;
class Board;
class Bonuse;

class CollisionObserver
{
public:
    CollisionObserver();

    ~CollisionObserver();

    bool IsCollideY(std::list<Bonuse>::iterator& bonuse) const;
    bool isPaddleCollide(std::list<Bonuse>::iterator& bonuse, Board& board) const;

    bool speedUpZone(Ball& ball) const;

    bool speedNormZone(Ball& ball) const;

    bool speedDownZone(Ball& ball) const;
    
    bool destroyBrick(std::list<Brick>::iterator brick, Ball& ball) const;
    
    bool IsCollideX(Ball &ball) const;

    bool IsCollideUpY(Ball &ball) const;
    bool IsCollideDownY(Ball& ball) const;

    bool isPaddleCollide(Ball& ball, Board &board) const;

    bool brickCollide(std::list<Brick>::iterator brick, Ball& ball);

    bool brickCollideY(std::list<Brick>::iterator brick, Ball& ball) const;
    bool brickCollideX(std::list<Brick>::iterator brick, Ball& ball) const;

private:
    bool EndGame{false};
};

