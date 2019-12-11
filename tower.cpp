#include <iostream>
#include <tower.h>

tower::tower():life(true)  //определение конструктора, устанавливаем life
{
	mTexture.loadFromFile("Textures/tower.png"); //загружаем текстуру башни из папки Textures, файла tower.png
	mSprite.setTexture(mTexture); //устанавливаем спрайт из текстуры
	mSprite.setPosition(576, 832); //устанавливаем в позицию на карте
}

tower::~tower() //определение деструктора 
{
	std::cout << "Tower destroyed\n"; //проверка удаления объекта класса - печать в консоль
}