#include <iostream>
#include <SFML/Graphics.hpp>
#include "map.h"

using namespace sf;
int main()
{
	const int s_size = 64;

	VideoMode desktop = VideoMode::getDesktopMode();
	RenderWindow window(VideoMode(s_size * WIDTH_MAP, s_size * HEIGHT_MAP, desktop.bitsPerPixel), "Tanks");
	window.setFramerateLimit(60);

	Texture herotexture;
	herotexture.loadFromFile("Textures/tank.png");

	Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.setPosition(8 * s_size, 6 * s_size);
	herosprite.setOrigin(32, 32);

	Texture wall;
	wall.loadFromFile("Textures/wall.png");
	sf::Sprite s_wall;

	Texture bg;
	bg.loadFromFile("Textures/bg.png");
	Sprite s_bg;

	Texture tower;
	tower.loadFromFile("Textures/tower.png");
	Sprite s_tower;

	Texture bullettexture;
	bullettexture.loadFromFile("Textures/bullet.png");

	Sprite bulletsprite;
	bulletsprite.setTexture(bullettexture);

	bool shot = false;
	int dir = 1, bdir = 1;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			dir = 3;
			herosprite.setTexture(herotexture);
			herosprite.move(-2.5, 0);
			herosprite.setRotation(270);
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			dir = 4;
			herosprite.setTexture(herotexture);
			herosprite.move(2.5, 0);
			herosprite.setRotation(90);

		}

		if (Keyboard::isKeyPressed(Keyboard::Up) && !Keyboard::isKeyPressed(Keyboard::Left) && !Keyboard::isKeyPressed(Keyboard::Right))
		{
			dir = 1;
			herosprite.setTexture(herotexture);
			herosprite.move(0, -2.5);
			herosprite.setRotation(0);
		}

		if (Keyboard::isKeyPressed(Keyboard::Down) && !Keyboard::isKeyPressed(Keyboard::Left) && !Keyboard::isKeyPressed(Keyboard::Right))
		{
			dir = 2;
			herosprite.setTexture(herotexture);
			herosprite.move(0, 2.5);
			herosprite.setRotation(180);
		}

		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			bdir = dir;
			switch (dir)
			{
			case 1:
				bulletsprite.setPosition(herosprite.getPosition().x - 8, herosprite.getPosition().y - 32);
				break;
			case 2:
				bulletsprite.setPosition(herosprite.getPosition().x - 8, herosprite.getPosition().y + 16);
				break;
			case 3:
				bulletsprite.setPosition(herosprite.getPosition().x - 32, herosprite.getPosition().y - 8);
				break;
			case 4:
				bulletsprite.setPosition(herosprite.getPosition().x + 16, herosprite.getPosition().y - 8);
				break;

			}
			shot = true;
		}

		if (shot)
		{
			switch (bdir)
			{
			case 1:
				bulletsprite.move(0, -3);
				break;
			case 2:
				bulletsprite.move(0, 3);
				break;
			case 3:
				bulletsprite.move(-3, 0);
				break;
			case 4:
				bulletsprite.move(3, 0);
				break;
			}
		}

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

		if (shot)
			window.draw(bulletsprite);

		window.draw(herosprite);
		window.display();
		window.clear();
	}
	return 0;
}