#ifndef _MAP_H_
#define _MAP_H_

#include <SFML\Graphics.hpp>
const int HEIGHT_MAP = 15;
const int WIDTH_MAP = 20;

std::string TileMap[HEIGHT_MAP] = {
	"00000000000000000000",
	"0   0   0000   0   0",
	"0  000        000  0",
	"00  0  000000  0  00",
	"00      0000      00",
	"000 0          0 000",
	"00  00  0000  00  00",
	"00  0          0  00",
	"0      00  00      0",
	"0 00   0    0   00 0",
	"0 00   0 00 0   00 0",
	"0 00            00 0",
	"0 00  0 0000 0  00 0",
	"0     0 0lp0 0     0",
	"00000000000000000000",
};

#endif