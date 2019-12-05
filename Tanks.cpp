#include <iostream>
#include <SFML/Graphics.hpp>
#include "map.h"

int main()
{
	const int s_size = 64;

	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(sf::VideoMode(s_size * WIDTH_MAP, s_size * HEIGHT_MAP, desktop.bitsPerPixel), "Tanks");

	sf::Texture herotexture;
	herotexture.loadFromFile("Textures/tank.png");
	sf::Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.setPosition(8 * s_size, 6 * s_size);

	sf::Texture wall;
	wall.loadFromFile("Textures/wall.png");
	sf::Sprite s_wall;

	sf::Texture bg;
	bg.loadFromFile("Textures/bg.png");
	sf::Sprite s_bg;

	sf::Texture tower;
	tower.loadFromFile("Textures/tower.png");
	sf::Sprite s_tower;

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
				switch (TileMap[i][j])
				{
				case ' ':
					s_bg.setTexture(bg);
					s_bg.setTextureRect(sf::IntRect(0, 0, s_size, s_size));
					s_bg.setPosition(j * s_size, i * s_size);
					window.draw(s_bg);
					break;

				case 'c':
					s_tower.setTexture(tower);
					s_tower.setTextureRect(sf::IntRect(0, 0, s_size, s_size));
					s_tower.setPosition(j * s_size, i * s_size);
					window.draw(s_tower);
					break;

				case '0':
					s_wall.setTexture(wall);
					s_wall.setTextureRect(sf::IntRect(6 * s_size, 0, s_size, s_size));
					s_wall.setPosition(j * s_size, i * s_size);
					window.draw(s_wall);
					break;

				case 'u':
					s_wall.setTexture(wall);
					s_wall.setTextureRect(sf::IntRect(3 * s_size, 0, s_size, s_size));
					s_wall.setPosition(j * s_size, i * s_size);
					window.draw(s_wall);
					break;

				case 'd':
					s_wall.setTexture(wall);
					s_wall.setTextureRect(sf::IntRect(5 * s_size, 0, s_size, s_size));
					s_wall.setPosition(j * s_size, i * s_size);
					window.draw(s_wall);
					break;

				case 'm':
					s_wall.setTexture(wall);
					s_wall.setTextureRect(sf::IntRect(2 * s_size, 0, s_size, s_size));
					s_wall.setPosition(j * s_size, i * s_size);
					window.draw(s_wall);
					break;
				}

		window.draw(herosprite);
		window.display();
	}

	return 0;
}