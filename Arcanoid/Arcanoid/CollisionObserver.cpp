#include "CollisionObserver.h"

#include"Brick.h"
#include "Ball.h"
#include "Board.h"
#include "Bonuse.h"

#include <list>

CollisionObserver::CollisionObserver()
{
}

CollisionObserver::~CollisionObserver()
{
}

bool CollisionObserver::destroyBrick(std::list<Brick>::iterator brick, Ball& ball) const
{
    if (brickCollideY(brick, ball))
    {
        return true;
    }

    if (brickCollideX(brick, ball))
    {
        return true;
    }

    return false;
}

bool CollisionObserver::IsCollideX(Ball& ball) const
{
    Vector<double> ballpos = ball.getPosition();
    Vector<int> ballsize = ball.getSize();
    if (ballpos.x <= 0 || (ballpos.x + ballsize.x) >= SCREEN_WIDTH)
    {
        return true;
    }
    return false;
}

bool CollisionObserver::IsCollideUpY(Ball& ball) const
{
    Vector<double> ballpos = ball.getPosition();
    Vector<int> ballsize = ball.getSize();
    if (ballpos.y <= 0)
    {
        return true;
    }
    return false;
}

bool CollisionObserver::IsCollideDownY(Ball& ball) const
{
    Vector<double> ballpos = ball.getPosition();
    Vector<int> ballsize = ball.getSize();
    if ((ballpos.y + ballsize.y) >= SCREEN_HEIGHT)
    {
        return true;
    }
    return false;
}
bool CollisionObserver::isPaddleCollide(Ball& ball, Board& board) const
{
    Vector<double> ballpos = ball.getPosition();
    Vector<int> ballsize = ball.getSize();
    Vector<int> boardsize = board.GetSize();
    Vector<int> boardpos = board.GetPosition();
    if ((boardpos.x <= (ballpos.x + ballsize.x) && ballpos.x <= (boardpos.x + boardsize.x)) && (boardpos.y <= ballpos.y))
    {
        return true;
    }
    return false;
}
bool CollisionObserver::brickCollide(std::list<Brick>::iterator brick, Ball& ball)
{
    Vector<double> ballpos = ball.getPosition();
    Vector<int> ballsize = ball.getSize();
    Vector<double> ballvelosity = ball.getVelocity();
    if (ballpos.x + ballsize.x + ballvelosity.x > brick->GetPosition().x
        &&
        ballpos.x + ballvelosity.x < brick->GetPosition().x + brick->GetSize().x
        &&
        ballpos.y + ballsize.y + ballvelosity.y > brick->GetPosition().y
        &&
        ballpos.y + ballvelosity.y < brick->GetPosition().y + brick->GetSize().y)
{
        printf("f");
        return true;
}
    return false;
}
bool CollisionObserver::brickCollideY(std::list<Brick>::iterator brick, Ball& ball) const
{
    Vector<double> ballpos = ball.getPosition();
    Vector<int> ballsize = ball.getSize();

    if (abs(ballpos.y - brick->GetPosition().y) <= COLLISION_DELTA
        ||
        abs(ballpos.y - (brick->GetPosition().y + brick->GetSize().y)) <= COLLISION_DELTA)
    {
        return true;
    }
    return false;
}

bool CollisionObserver::brickCollideX(std::list<Brick>::iterator brick, Ball& ball) const
{
    Vector<double> ballpos = ball.getPosition();
    Vector<int> ballsize = ball.getSize();
    if (abs(ballpos.x - brick->GetPosition().x) <= COLLISION_DELTA
        ||
        abs(ballpos.x - (brick->GetPosition().x + brick->GetSize().x)) <= COLLISION_DELTA)
    {
        return true;
    }
    return false;
}

bool CollisionObserver::IsCollideY(std::list<Bonuse>::iterator& bonuse) const
{
    Vector<int> bonusesize = bonuse->GetSize();
    Vector<int> bonusepos = bonuse->GetPosition();
    if ((bonusepos.y + bonusesize.y) >= SCREEN_HEIGHT)
    {
        return true;
    }
    return false;
}

bool CollisionObserver::isPaddleCollide(std::list<Bonuse>::iterator& bonuse, Board& board) const
{
    Vector<int> bonusepos = bonuse->GetPosition();
    Vector<int> bonusesize = bonuse->GetSize();
    Vector<int> boardsize = board.GetSize();
    Vector<int> boardpos = board.GetPosition();
    if ((boardpos.x < (bonusepos.x + bonusesize.x) && bonusepos.x < (boardpos.x + boardsize.x)) && (boardpos.y <= bonusepos.y))
    {
        return true;
    }
    return false;
}

bool CollisionObserver::speedUpZone(Ball& ball) const
{
    Vector<double> ballpos = ball.getPosition();
    Vector<int> ballsize = ball.getSize();
    if (ballpos.y + ballsize.y < SCREEN_HEIGHT / 2)
    {
        return true;
    }
}

bool CollisionObserver::speedNormZone(Ball& ball) const
{
    Vector<double> ballpos = ball.getPosition();
    Vector<int> ballsize = ball.getSize();
    if (ballpos.y + ballsize.y > SCREEN_HEIGHT / 2 && ballpos.y + ballsize.y < 3 * SCREEN_HEIGHT / 4 )
    {
        return true;
    }
}

bool CollisionObserver::speedDownZone(Ball& ball) const
{
    Vector<double> ballpos = ball.getPosition();
    Vector<int> ballsize = ball.getSize();
    if (ballpos.y + ballsize.y > 3*SCREEN_HEIGHT / 4)
    {
        return true;
    }
    return false;
}