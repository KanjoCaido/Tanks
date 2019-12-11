#pragma once
#include <SFML/Graphics.hpp>

class map; //класс карты, подключаем дл€ функции взаимодействи€ с картой

class bullet //класс пули 
{
private:
	float b_x, b_y, b_dx, b_dy; //координаты пули, приращение координаты по иксу и игреку
	
	enum BDIR //перечисление направлений движени€ пули
	{ 
		left = 0, 
		right = 1, 
		up = 2, 
		down = 3 
	} b_dir;

	sf::Texture b_Texture; //текстура пули

public:
	bool present; //булевска€ переменна€ - отвечает за проверку еЄ присутстви€,
	char owner; //буквенна€ переменна€ - отвечает за проверку танка, пустившего еЄ - врага, или игрока

	sf::Sprite b_Sprite; //спрайт пули

	bullet(const float x, const float y, const char owner, const int bdir); //объ€вление конструктора с параметрами - координатами пули, 
																													//еЄ владельца и еЄ направлением
	~bullet(); //объ€вление деструктора пули

	void shoot() //функци€ выстрела пули
	{ 
		present = true; //выстрелил - значит пул€ присутствует
	}

	void move(const sf::Int64 time); //объ€вление функции-перемещени€ пули

	void update(map& map, const sf::Int64 time, float x, const float y, const int dir);  //объ€вление функции-обновлени€ объекта-пули во врем€ игры по карте

	void map_interaction(map& map); //объ€вление функции-взаимодействи€ пули с картой


};
