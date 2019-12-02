#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(sf::VideoMode(1024, 768, desktop.bitsPerPixel), "Tanks");

	sf::Texture herotexture;
	herotexture.loadFromFile("Textures/tank.png");
	sf::Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.setPosition(50, 25);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(herosprite);
		window.display();
	}

	return 0;
}