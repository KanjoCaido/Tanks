#include <iostream>
#include <SFML/Window.hpp>
#include <game.h>

game::game(): Window(sf::VideoMode(1216, 960), "Tanks"), gameOver(false), gameStarted(false),
			  msgStart(165, 420, "Press \'Enter\' to start"), msgOver(415, 415, "Game over"),
	          msgLost(415, 480, "You lost!"), msgWon(440, 480, "You won!"), frags(0)
//определение конструктора, передаем в него ширину, высоту окна, название окна
//устанавливаем состояния игры - неокончена, неначата, сообщение о просьбе нажатия клавиши 'Enter' для начала игры, 
//сообщения о конце игры, проигрыше, выйгрыше, кол-во фрагов устанавливаем на 0
{
	sf::Clock clock; //объект clock для отслеживания прошедшего с начала игры времени

	Window.setFramerateLimit(60); //устанавливаем ограничение кадров на 60 в секунду

	elist(); //вызываем функцию, в которой заполняем список врагами

	while (Window.isOpen()) //пока открыто окно с игрой
	{
		sf::Int64 time = clock.getElapsedTime().asMicroseconds(); //считываем прошедшее время с запуска или перезапуска часов
		clock.restart(); //перезапускаем часы
		time /= 800; //скорость игры

		process_events(); //вызываем функцию обработки событий

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) //если нажали клавишу 'Enter'
			gameStarted = true; //начинаем игру

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) //если нажали клавишу 'Escape'
			gameOver = true; //оканчиваем игру

		if (gameStarted && !gameOver) //Если игра началась и ещё не окончилась
			update(time); //обновляем игру
		render(); //рисуем объекты
	}

	//после закрытия окна
	for (itb = Bullets.begin(); itb != Bullets.end(); itb++) //от начала до конца списка пуль
	{
		delete (*itb); //вычищаем память от объектов-пуль
	}

	for (ite = Enemies.begin(); ite != Enemies.end(); ite++) //от начала до конца списка врагов
	{
		delete (*ite); //вычищаем память от объектов-врагов
	}
}

game::~game() //определение деструктора
{
	std::cout << "Game destroyed\n"; //выводим сообщение для проверки удаления объекта
}

void game::process_events() //объявление функции обработки событий
{
	sf::Event event; //объект event, который определяет событие системы и её параметры
	while (Window.pollEvent(event)) //производим опрос события
	{
		switch (event.type) //если
		{
		case sf::Event::Closed: //событие Closed
			Window.close(); //закрываем окно
			break;
		}
	}
}

void game::update(const sf::Int64 time) //объявление функции обновления игры
{
	for (ite = Enemies.begin(); ite != Enemies.end(); ite++) //проходимся по списку врагов
		if (!(*ite)->life) //если умер
			++frags; //добавляем 1 к кол-ву фрагов
		else //иначе
		{
			frags = 0; //обнуляем кол-во убийств
			break;
		}

	if (frags == 4) //если четыре убийства
		gameOver = true; //игра окончена

	if (!Player.life) //если игрок умер
		gameOver = true; //игра окончена

	for (itb = Bullets.begin(); itb!= Bullets.end(); ) //проходимся по списку пуль
	{
		if (!(*itb)-> present) //если пуля отсутствует
		{ 
			delete (*itb); //вычищаем память
			itb = Bullets.erase(itb); //убираем из списка
		} 
		else //иначе
			itb++; //идем дальше по списку
	}

	for (itb = Bullets.begin(); itb != Bullets.end(); itb++) //проходимся по списку пуль
	{
		if ((*itb)->owner == 'p' && (*itb)->present == true) //если пулю запустил игрок и она присутствует на карте
			(*itb)->update(Map, time, Player.t_x, Player.t_y, Player.t_dir); //обновляем пулю с координатами игрока
		if ((*itb)->owner == 'e' && (*itb)->present == true) //если пулю запустил враг и она присутствует на карте
			for (ite = Enemies.begin(); ite != Enemies.end(); ite++) //проходимся по списку врагов
			{
				(*itb)->update(Map, time / 4, (*ite)->t_x, (*ite)->t_y, (*ite)->t_dir); //обновляем пулю с координатами врага
			}
	}

	if (Player.life) //если игрок жив
	{
		Player.update(time, Map); //обновляем его
		Player.timeBeforeShot += time; //приращаем время до выстрела 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) //если нажали пробел
		{
			if (Player.timeBeforeShot > 500) //если игрок не стрелял полсекунды
			{
				Bullets.push_back(new bullet(Player.t_x + 24, Player.t_y + 32, 'p', Player.t_dir)); //отправляем в контейнер объект-пулю
				itb = Bullets.end(); //переходим на конец списка
				itb--; //переходим на новосозданную пулю
				(*itb)->update(Map, time, Player.t_x, Player.t_y, Player.t_dir); //обновляем её
				(*itb)->present = true; //присутствует
				Player.timeBeforeShot = 0; //обнуляем время до выстрела
			}
		}
	}


	for (ite = Enemies.begin(); ite != Enemies.end(); ite++) //идем по списку врагов
	{
		if ((*ite)->life) //если враг жив
		{
			(*ite)->update(time, Map); //обновляем его
			(*ite)->timeBeforeShot += time; //приращаем время до выстрела 

			if ((*ite)->timeBeforeShot > 1000) //если враг не стрелял секунду
			{
				if (rand() % 2) //случайно выбираем истину или ложь, если 1
				{
					Bullets.push_back(new bullet((*ite)->t_x, (*ite)->t_y, 'e', (*ite)->t_dir)); //отправляем в контейнер объект-пулю
					itb = Bullets.end(); //переходим на конец списка
					itb--; //переходим на новосозданную пулю
					(*itb)->update(Map, time, (*ite)->t_x, (*ite)->t_y, (*ite)->t_dir); //обновляем её
					(*itb)->present = true; //присутствует
				}
			(*ite)->timeBeforeShot = 0; //обнуляем время до выстрела
			}

			if ((*ite)->t_Sprite.getGlobalBounds().intersects(Player.t_Sprite.getGlobalBounds())) //если спрайт врага пересекается со спрайтом игрока
				Player.collapse(); //игрок умер

			for (itb = Bullets.begin(); itb != Bullets.end(); itb++) //проходимся по списку пуль
			{
				if ((*itb)->b_Sprite.getGlobalBounds().intersects(Player.t_Sprite.getGlobalBounds()) && (*itb)->owner == 'e') //если выстрелил враг и спрайт пули пересекся со спрайтом игрока
				{
					Player.collapse(); //игрок умер
					(*itb)->present = false; //пуля отсутствует
				}

				if ((*itb)->b_Sprite.getGlobalBounds().intersects(Tower.mSprite.getGlobalBounds())) //спрайт пули пересекся со спрайтом башни
				{
					Tower.life = false; //уничтожили башню
					gameOver = true; //игра окончена
				}

				if ((*itb)->b_Sprite.getGlobalBounds().intersects((*ite)->t_Sprite.getGlobalBounds()) && (*itb)->owner == 'p') //если выстрелил игрок и спрайт пули пересекся со спрайтом врага
				{
					(*ite)->collapse(); //враг умер
					(*itb)->present = false; //пуля отсутствует
				}
			}
		}
	}
}

void game::render() //определение функции обновления игры, в которой рисуются объекты игры
{
	Window.clear(); //очищаем окно
	Map.draw(Window); //рисуем карту
	if (Player.life) //если игрок жив
		Window.draw(Player.t_Sprite); //рисуем игрока

	for (itb = Bullets.begin(); itb != Bullets.end(); itb++) //проходимся по списку пуль
	if ((*itb)->present) //если пуля присутствует
		Window.draw((*itb)->b_Sprite); //рисуем

	for (ite = Enemies.begin(); ite != Enemies.end(); ite++) //проходимся по списку врагов
	{ 
		if ((*ite)->life) //если враг жив
			Window.draw((*ite)->t_Sprite); //рисуем
	}

	if (Tower.life) //если башня не уничтожена
		Window.draw(Tower.mSprite);  //рисуем

	if (!gameStarted) //если игра не началась 
		msgStart.print(Window); //выводим сообщение о старте игры

	if (gameOver) //если игра окончена
	{
		msgOver.print(Window); //выводем сообщение об окончании игры

		if (!Tower.life || !Player.life) //если башня уничтожена или убит игрок
			msgLost.print(Window); //выводим сообщение о проигрыше
		if (frags == 4) //если игрок убил всех четверых противников
			msgWon.print(Window); //выводим сообщение о победе
	} 

	Window.display(); //отоброжаем результат в окне
}