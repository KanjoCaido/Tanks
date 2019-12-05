
#ifndef _MAP_H_
#define _MAP_H_

#include <SFML\Graphics.hpp>
const int HEIGHT_MAP = 13;
const int WIDTH_MAP = 17;

std::string TileMap[HEIGHT_MAP] = {
	"   u   m0m   u   ",
	"  m0m       m0m  ",
	"u  d  m0 0m  d  u",
	"d      d d      d",
	"0m u         u m0",
	"d  0m  m0m  m0  d",
	"   d         d   ",
	"      0m m0      ",
	" u  u u   u u  u ",
	" d0 d d 0 d d 0d ",
	" 0u           u0 ",
	"  d  u m0m u  d  ",
	"     d 0c0 d     ",
};

#endif