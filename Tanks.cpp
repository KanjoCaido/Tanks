#include <iostream>
#include <SFML/Graphics.hpp>
#include "map.h"

int main()
{
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(sf::VideoMode(640, 480, desktop.bitsPerPixel), "Tanks");

	sf::Texture herotexture;
	herotexture.loadFromFile("Textures/tank.png");
	sf::Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.setPosition(64, 64);

/*	sf::Texture kokotexture;
	kokotexture.loadFromFile("Textures/koko.png");
	sf::Sprite kokosprite;
	kokosprite.setTexture(kokotexture); */

	sf::Texture bgtexture;
	bgtexture.loadFromFile("Textures/bg.png");
	sf::Sprite bgsprite;
	bgsprite.setTexture(bgtexture);

	sf::Texture walltexture;
	walltexture.loadFromFile("Textures/wall.png");
	sf::Sprite wallsprite;
	wallsprite.setTexture(walltexture);

	sf::Image map_image;
	map_image.loadFromFile("Textures/bg.png");
	sf::Texture map;
	map.loadFromImage(map_image);
	sf::Sprite s_map;
	s_map.setTexture(map); 

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ') s_map.setTexture(bgtexture); 
				if (TileMap[i][j] == '0') s_map.setTexture(walltexture);
//				if (TileMap[i][j] == 'l') s_map.setTextureRect(sf::IntRect(0,0,16,32));
//				if (TileMap[i][j] == 'p') s_map.setTextureRect(sf::IntRect(16,0,32,32));
				s_map.setPosition(j * 32, i * 32);
				window.draw(s_map);
			}

		window.draw(herosprite);
		window.display();
	}

	return 0;
}