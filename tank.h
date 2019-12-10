#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class map; //класс карты, подключаем дл€ функции взаимодействи€ с картой

class tank  //класс танка, предок классов игрока и танков-противников
{
protected:
	float t_dx, t_dy, t_Speed, t_CurrentFrame; //приращение координаты по иксу и игреку, скорость движени€ танка, нынешний фрейм танка

	sf::String t_File; //файл с текстурой танка
	sf::Texture t_Texture; //текстура танка

public:
	tank(const float x, const float y, const sf::String file); //объ€вление конструктора с параметрами - координатами танка и его текстурой

	virtual ~tank(); //объ€вление виртуального деструктора - потому что предок

	float t_x, t_y; //координаты танка
	bool life; //булевска€ переменна€, отвечающа€ за то, уничтожен танк врагом, или нет

	enum TDIR //перечисление направлений движени€ танка
	{ 
		left = 0, 
		right = 1, 
		up = 2, 
		down = 3
	} t_dir;

	sf::Sprite t_Sprite; //спрайт танка

	void animate(const sf::Int64 time); //объ€вление функции с анимацией танка, в качестве аргумента врем€ игры

	void collapse(); //объ€вление функции-уничтожени€ танка

	virtual void move(const sf::Int64 time) //виртуальна€ функци€ перемещени€ танка, переопределитс€ у потомков
	{

	}
	
	void map_interaction(map& map); //объ€вление функции-взаимодействи€ танка с картой
};