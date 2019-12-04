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
	//herosprite.setTextureRect(IntRect(0, 192, 96, 96));
	herosprite.setPosition(250, 250); //задаем начальные координаты появления спрайта 

	while (window.isOpen())  //Пока окно открыто 
	{
		Event event; //Переменная для события
		while (window.pollEvent(event)) //Опрос событий 
		{
			if (event.type == Event::Closed)
				window.close(); //Закрываем окно, если событие “Closed” 
		}

		//координата Y, на которой герой изображен идущим влево равна 96   
		if (Keyboard::isKeyPressed(Keyboard::Left)) 
		{    
			herosprite.move(-0.1, 0); 
			herosprite.setTextureRect(IntRect(0, 0, 96, 96));    
		} 

		//координата Y, на которой герой изображен идущем вправо равна 96+96=192   
		if (Keyboard::isKeyPressed(Keyboard::Right)) 
		{    
			herosprite.move(0.1, 0); 
			herosprite.setTextureRect(IntRect(0, 0, 96, 96));    
		} 

		//координата Y на которой герой изображен идущим вверх равна 288   
		if (Keyboard::isKeyPressed(Keyboard::Up)) 
		{    
			herosprite.move(0, -0.1); 
			herosprite.setTextureRect(IntRect(0, 0, 96, 96));    
		} 

		//координата 0, это верхняя часть изображения с героем, от нее и отталкиваемся    
		//ровными квадратиками по 96.   
		if (Keyboard::isKeyPressed(Keyboard::Down)) 
		{    herosprite.move(0, 0.1); 
		herosprite.setTextureRect(IntRect(0, 0, 96, 96));    
		}   


		window.clear(); //Очищаем экран 
		window.draw(herosprite); //Рисуем herosprite
		window.display(); //Отображаем herosprite на экран 
	}

	return 0;
}