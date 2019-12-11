#pragma once
#include <SFML/Graphics.hpp>
#include <map.h>
#include <player.h>
#include <enemy.h>
#include <tower.h>
#include <message.h>
#include <list>

class game //класс игры
{
private:
	bool gameOver; //булевска€ переменна€-состо€ние игры (закончена/не закончена)
	bool gameStarted; //булевска€ переменна€-начало игры (начата/не начата)

	int frags; //переменна€, в которой отслеживает количество уничтоженных игроком танков-врагов

	sf::RenderWindow Window; //объект Window класса RenderWindow, в котором будет отрисовыватьс€ наша игра
	tower Tower; //объект-башн€
	map Map; //объект-карта
	player Player; //объект-игрок

	std::list<enemy*> Enemies; //список с врагами
	std::list<enemy*>::iterator ite; //итератор дл€ работы с этим списком

	std::list<bullet*> Bullets; //список с пул€ми 
	std::list<bullet*>::iterator itb; //итератор дл€ работы с этим списком

	int ex[4] = { 64 , 1088 , 64 , 1088 }; //массив координат врагов по x
	int ey[4] = { 64 , 65 , 448 , 448 }; //массив координат врагов по y

	message msgStart; //объект-сообщение о старте игры
	message msgOver; //объект-сообщение о конце игры
	message msgLost; //объект-сообщение о проигрыше игры
	message msgWon; //объект-сообщение о выйгрыше игры

public:
	game(); //объ€вление конструктора без параметров

	~game(); //объ€вление деструктора

	void elist() //функци€, в которой заполн€етс€ список врагами с координатами из массива
	{
		for (int i = 0; i < 4; i++) //4 врага
			Enemies.push_back(new enemy(ex[i], ey[i])); //отправл€ем последовательно в конец списка
	}

	void process_events(); //объ€вление функции обработки событий
	void update(const sf::Int64 time); //объ€вление функции обновлени€ игры
	void render(); //объ€вление функции обновлени€ игры, в которой рисуютс€ объекты игры
};
