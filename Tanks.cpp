#include <SFML/Graphics.hpp> 
using namespace sf;
int main()
{
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(sf::VideoMode(1024, 768, desktop.bitsPerPixel), "Enemy-tank");
	Texture enemytexture;
	enemytexture.loadFromFile("Textures/enemytanks.png");
	Sprite enemysprite;
	enemysprite.setTexture(enemytexture);
	enemysprite.setTextureRect(IntRect(0, 0, 84, 84));//получили нужный прямоугольник 
	enemysprite.setPosition(512, 384);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(enemysprite);
		window.display();
	}
	return 0;
}
