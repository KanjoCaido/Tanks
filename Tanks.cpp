#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
	VideoMode desktop = sf::VideoMode::getDesktopMode();
	RenderWindow window(sf::VideoMode(1024, 768, desktop.bitsPerPixel), "Tanks");
	window.setFramerateLimit(60);

	Texture herotexture;
	herotexture.loadFromFile("Textures/tank.png");

	Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.setPosition(250, 250);
	herosprite.setOrigin(32, 32);

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

		window.clear();

		if (shot)
			window.draw(bulletsprite);

		window.draw(herosprite);
		window.display();
	}
	return 0;
}