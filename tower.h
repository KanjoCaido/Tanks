#pragma once
#include <SFML/Graphics.hpp>

class tower  //класс башни, которую мы защищаем
{
private:
	sf::Texture mTexture; //еЄ текстура

public:
	sf::Sprite mSprite; //еЄ спрайт
	bool life; //булевска€ переменна€, отвечающа€ за то, уничтожена она, или нет

	tower(); //объ€вление еЄ конструктора без параметров
	~tower(); //объ€вление деструктора
};