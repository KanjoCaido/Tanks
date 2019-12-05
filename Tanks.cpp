#include <SFML/Graphics.hpp> 
#include <iostream>
using namespace sf;
using namespace std;
int main()
{
	float bulletspeed = 0.5, t = 0;
	bool shot = false;
	VideoMode desktop = VideoMode::getDesktopMode();
	RenderWindow window(VideoMode(1024, 768, desktop.bitsPerPixel), "Enemy-tank");

	Texture enemytexture;
	enemytexture.loadFromFile("Textures/enemytanks.png");
	Sprite enemysprite;
	enemysprite.setTexture(enemytexture);
	enemysprite.setTextureRect(IntRect(0, 0, 84, 84));
	enemysprite.setPosition(42, 42);
	enemysprite.setOrigin(42, 42);
	enemysprite.setRotation(180);
	Texture bullettexture;
	bullettexture.loadFromFile("Textures/bullet.png");
	Sprite bulletsprite;
	bulletsprite.setTexture(bullettexture);
	Clock clock;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		t += time;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();

		window.draw(enemysprite);
		if ((t > 300) && (shot == false))
		{

			bulletsprite.setPosition(enemysprite.getPosition().x - 8, enemysprite.getPosition().y + 32);
			shot = true;
		}
		if (t > 2000)
		{
			shot = false;
			t = 0;
		}
		if (shot)
		{
			bulletsprite.move(0, bulletspeed*time);
			window.draw(bulletsprite);
		}

		window.display();
	}
	return 0;
}