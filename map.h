#ifndef _MAP_H_
#define _MAP_H_

#include <SFML\Graphics.hpp>
const int HEIGHT_MAP = 15;
const int WIDTH_MAP = 19;

std::string TileMap[HEIGHT_MAP] = {
	"0000000000000000000",
	"0   0   000   0   0",
	"0  000       000  0",
	"00  0  00000  0  00",
	"00      000      00",
	"000 0         0 000",
	"00  00  000  00  00",
	"00  0         0  00",
	"0      00 00      0",
	"0 00   0   0   00 0",
	"0 00   0 0 0   00 0",
	"0 00           00 0",
	"0 00  0 000 0  00 0",
	"0     0 0c0 0     0",
	"0000000000000000000",
};

#endif