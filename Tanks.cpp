#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;//включаем пространство имен sf, чтобы постоянно не писать sf::

int main()
{
	// Создаём окно с той же битовой глубиной пикселей, что и рабочий стол 
	VideoMode desktop = sf::VideoMode::getDesktopMode();
	RenderWindow window(sf::VideoMode(1024, 768, desktop.bitsPerPixel), "Tanks");


	Texture herotextureA, herotextureB, herotextureC, herotextureD; //cоздаем объект Texture(текстура)
	herotextureA.loadFromFile("Textures/tank.png"); //передаем в него объект Image (изображения) 
	/*herotextureB.loadFromFile("Textures/tankB.png");
	herotextureC.loadFromFile("Textures/tankC.png");
	herotextureD.loadFromFile("Textures/tankD.png");*/


	Sprite herosprite; //создаем объект Sprite(спрайт) 
	herosprite.setTexture(herotextureA); //передаём в него объект Texture (текстуры) 
	herosprite.setPosition(250, 250); //задаем начальные координаты появления спрайта 
	herosprite.setOrigin(32, 32);

	float CurrentFrame = 0;//хранит текущий кадр  
	Clock clock;  //создаем переменную времени и одновременно запускаем часы! 


	while (window.isOpen())  //Пока окно открыто 
	{

		// дать время с последнего перезапуска часов, в данном случае время, прошедшее с               
		//предыдущей итерации и вызова restart();   
		float time = clock.getElapsedTime().asMicroseconds();    
		clock.restart(); //перезапуск часов   
		time = time / 800; //скорость игры   


		Event event; //Переменная для события
		while (window.pollEvent(event)) //Опрос событий 
		{
			if (event.type == Event::Closed)
				window.close(); //Закрываем окно, если событие “Closed” 
		}

		
		//координата Y, на которой герой изображен идущим влево равна 96   
		if (((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))))
		{    
			//если нажата клавиша стрелка влево или англ буква А   
			CurrentFrame += 0.000005*time; 

			//служит для прохождения по "кадрам". переменная доходит до трех, суммируя произведение 
			//времени и скорости. Изменив 0.005, можно изменить скорость анимации    
			if (CurrentFrame > 3) CurrentFrame -= 3; //если пришли к третьему кадру - 
													 //откатываемся назад. 
			
			herosprite.setTextureRect(IntRect(96 * int(CurrentFrame), 0, 96, 96));
			herosprite.move(-0.1 * time, 0); //происходит движение персонажа влево
			herosprite.setRotation(270);
			
			
		} 

		//координата Y, на которой герой изображен идущем вправо равна 96+96=192   
		if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))))
		{    
			CurrentFrame += 0.000005 * time;     
			if (CurrentFrame > 3) CurrentFrame -= 3;

			//herosprite.setTexture(herotextureB);
			herosprite.setTextureRect(IntRect(96 * int(CurrentFrame), 0, 96, 96));
			herosprite.move(0.1 * time, 0);
			herosprite.setRotation(90);
			
		} 

		//координата Y на которой герой изображен идущим вверх равна 288   
		if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W))))
		{    
			CurrentFrame += 0.000005 * time;     
			if (CurrentFrame > 3) CurrentFrame -= 3;

			//herosprite.setTexture(herotextureA);
			herosprite.setTextureRect(IntRect(96 * int(CurrentFrame), 0, 96, 96));
			herosprite.move(0, -0.1 * time);
			herosprite.setRotation(0);
			
		} 

		  
		if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S))))
		{   
			CurrentFrame += 0.000005 * time;     
			if (CurrentFrame > 3) CurrentFrame -= 3;

			//herosprite.setTexture(herotextureC);
			 
			herosprite.setTextureRect(IntRect(96 * int(CurrentFrame), 0, 96, 96));
			herosprite.move(0, 0.1 * time);
			herosprite.setRotation(180);
			
		}   


		window.clear(); //Очищаем экран 
		window.draw(herosprite); //Рисуем herosprite
		window.display(); //Отображаем herosprite на экран 
	}

	return 0;
}