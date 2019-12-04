#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;//включаем пространство имен sf, чтобы постоянно не писать sf::

int main()
{
	// Создаём окно с той же битовой глубиной пикселей, что и рабочий стол 
	VideoMode desktop = sf::VideoMode::getDesktopMode();
	RenderWindow window(sf::VideoMode(1024, 768, desktop.bitsPerPixel), "Tanks");

	Texture herotexture; //cоздаем объект Texture(текстура)
	herotexture.loadFromFile("Textures/tank.png"); //передаем в него объект Image (изображения) 

	Sprite herosprite; //создаем объект Sprite(спрайт) 
	herosprite.setTexture(herotexture); //передаём в него объект Texture (текстуры) 
	herosprite.setPosition(50, 25); //задаем начальные координаты появления спрайта 

	while (window.isOpen())  //Пока окно открыто 
	{
		Event event; //Переменная для события
		while (window.pollEvent(event)) //Опрос событий 
		{
			if (event.type == Event::Closed)
				window.close(); //Закрываем окно, если событие “Closed” 
		}

		window.clear(); //Очищаем экран 
		window.draw(herosprite); //Рисуем herosprite
		window.display(); //Отображаем herosprite на экран 
	}

	return 0;
}