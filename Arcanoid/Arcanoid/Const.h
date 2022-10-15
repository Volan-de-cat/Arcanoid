#pragma once

#include <string>
#include <array>

template <class T>
struct Vector 
{
	T x, y;
};

const int SCREEN_HEIGHT = 800;
const int SCREEN_WIDTH = 600;

const double COLLISION_DELTA = 2.5;

const std::string backgroundPath = "../data/1617571381_2-p-anime-zadnii-fon-2.jpg";

const std::string boardPath = "../data/56-Breakout-Tiles.png";
const int boardsizex = 100;
const int boardsizey = 20;

const std::string ballPath = "../data/64-Breakout-Tiles.png";
const int ballsizex = 20;
const int ballsizey = 20;

const std::array<std::string, 5>brickPath
{
	"../data/01-Breakout-Tiles.png",
	"../data/03-Breakout-Tiles.png",
	"../data/05-Breakout-Tiles.png",
	"../data/07-Breakout-Tiles.png",
	"../data/09-Breakout-Tiles.png"
};
const int bricksizex = 100;
const int bricksizey = 40;

const std::array<std::string, 4>bonusePath
{
	"../data/46-Breakout-Tiles.png",
	"../data/47-Breakout-Tiles.png",
	"../data/48-Breakout-Tiles.png",
	"../data/49-Breakout-Tiles.png"
};
const int bonusesizex = 60;
const int bonusesizey = 20;
const int bonusespeed = 1;