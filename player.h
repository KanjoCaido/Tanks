#pragma once
#include <SFML/Window.hpp>
#include <tank.h>

class player : public tank //класс игрока - наследует пол€ и методы класса танка с модификатором доступа public
{
public:
	player(); //объ€вление конструктора без параметров

	~player(); //объ€вление деструктора наследника

	float timeBeforeShot; //переменна€ - врем€ до выстрела
	void move(const sf::Int64 time); //объ€вление функции-перемещени€ игрока
	void update(const sf::Int64 time, map& map); //объ€вление функции-обновлени€ объекта-игрока во врем€ игры по карте
};