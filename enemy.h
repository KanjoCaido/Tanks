#pragma once
#include <tank.h>

class enemy : public tank //класс врага - наследует пол€ и методы класса танка с модификатором доступа public
{
public:
	enemy(const float x, const float y); //объ€вление конструктора с параметрами - координатами
	enemy(const enemy& enemy) : enemy(enemy.t_x, enemy.t_y) //конструктор копировани€ - дл€ копировани€ объекта, создани€ нескольких копий	
	{

	}

	~enemy(); //объ€вление деструктора наследника

	float timeBeforeMoving; //переменна€ - врем€ до смены направлени€ движени€
	float timeBeforeShot; //переменна€ - врем€ до выстрела

	void move(const sf::Int64 time); //объ€вление функции-перемещени€ врага
	void update(const sf::Int64 time, map& map); //объ€вление функции-обновлени€ объекта-врага во врем€ игры по карте
};
