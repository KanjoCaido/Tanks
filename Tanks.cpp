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

	sf::Texture bgtexture;
	bgtexture.loadFromFile("Textures/bg.png");
	sf::Sprite bgsprite;
	bgsprite.setTexture(bgtexture);

	sf::Texture walltexture;
	walltexture.loadFromFile("Textures/wall.png");
	sf::Sprite wallsprite;
	wallsprite.setTexture(walltexture);

	sf::Image map_image;//объект изображения для карты
	map_image.loadFromFile("Textures/bg.png");//загружаем файл для карты
	sf::Texture map;//текстура карты
	map.loadFromImage(map_image);//заряжаем текстуру картинкой
	sf::Sprite s_map;//создаём спрайт для карты
	s_map.setTexture(map);//заливаем текстуру спрайтом 

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
				if (TileMap[i][j] == ' ') s_map.setTexture(bgtexture); //если
				//встретили символ пробел, то рисуем 1-й квадратик
				if ((TileMap[i][j] == '0')) s_map.setTexture(walltexture);//если
				//встретили символ 0, то рисуем 3й квадратик
				s_map.setPosition(j * 32, i * 32);//раскладываем квадратики в карту.
				window.draw(s_map);//рисуем квадратики на экран
			}

		window.draw(herosprite);
		window.display();
	}

	return 0;
}