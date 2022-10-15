#include "Background.h"

Background::Background()
	:_pos({0,0})
{
}

void Background::Init()
{
	_background = createSprite(backgroundPath.c_str());
}

void Background::Draw()
{
	drawSprite(_background, _pos.x, _pos.y);
}
