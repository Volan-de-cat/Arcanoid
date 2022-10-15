#include "Background.h"

Background::Background()
{

}

void Background::Init()
{
	_screen = createSprite(screenPath.c_str());
}

void Background::Draw()
{
	drawSprite(_screen, _pos.x, _pos.y);
}
