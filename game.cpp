#include <iostream>
#include <SFML/Window.hpp>
#include <game.h>

game::game(): Window(sf::VideoMode(1216, 960), "Tanks"), gameOver(false), gameStarted(false),
			  msgStart(165, 420, "Press \'Enter\' to start"), msgOver(415, 415, "Game over"),
	          msgLost(415, 480, "You lost!"), msgWon(440, 480, "You won!"), frags(0)
//����������� ������������, �������� � ���� ������, ������ ����, �������� ����
//������������� ��������� ���� - ����������, ��������, ��������� � ������� ������� ������� 'Enter' ��� ������ ����, 
//��������� � ����� ����, ���������, ��������, ���-�� ������ ������������� �� 0
{
	sf::Clock clock; //������ clock ��� ������������ ���������� � ������ ���� �������

	Window.setFramerateLimit(60); //������������� ����������� ������ �� 60 � �������

	elist(); //�������� �������, � ������� ��������� ������ �������

	while (Window.isOpen()) //���� ������� ���� � �����
	{
		sf::Int64 time = clock.getElapsedTime().asMicroseconds(); //��������� ��������� ����� � ������� ��� ����������� �����
		clock.restart(); //������������� ����
		time /= 800; //�������� ����

		process_events(); //�������� ������� ��������� �������

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) //���� ������ ������� 'Enter'
			gameStarted = true; //�������� ����

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) //���� ������ ������� 'Escape'
			gameOver = true; //���������� ����

		if (gameStarted && !gameOver) //���� ���� �������� � ��� �� ����������
			update(time); //��������� ����
		render(); //������ �������
	}

	//����� �������� ����
	for (itb = Bullets.begin(); itb != Bullets.end(); itb++) //�� ������ �� ����� ������ ����
	{
		delete (*itb); //�������� ������ �� ��������-����
	}

	for (ite = Enemies.begin(); ite != Enemies.end(); ite++) //�� ������ �� ����� ������ ������
	{
		delete (*ite); //�������� ������ �� ��������-������
	}
}

game::~game() //����������� �����������
{
	std::cout << "Game destroyed\n"; //������� ��������� ��� �������� �������� �������
}

void game::process_events() //���������� ������� ��������� �������
{
	sf::Event event; //������ event, ������� ���������� ������� ������� � � ���������
	while (Window.pollEvent(event)) //���������� ����� �������
	{
		switch (event.type) //����
		{
		case sf::Event::Closed: //������� Closed
			Window.close(); //��������� ����
			break;
		}
	}
}

void game::update(const sf::Int64 time) //���������� ������� ���������� ����
{
	for (ite = Enemies.begin(); ite != Enemies.end(); ite++) //���������� �� ������ ������
		if (!(*ite)->life) //���� ����
			++frags; //��������� 1 � ���-�� ������
		else //�����
		{
			frags = 0; //�������� ���-�� �������
			break;
		}

	if (frags == 4) //���� ������ ��������
		gameOver = true; //���� ��������

	if (!Player.life) //���� ����� ����
		gameOver = true; //���� ��������

	for (itb = Bullets.begin(); itb!= Bullets.end(); ) //���������� �� ������ ����
	{
		if (!(*itb)-> present) //���� ���� �����������
		{ 
			delete (*itb); //�������� ������
			itb = Bullets.erase(itb); //������� �� ������
		} 
		else //�����
			itb++; //���� ������ �� ������
	}

	for (itb = Bullets.begin(); itb != Bullets.end(); itb++) //���������� �� ������ ����
	{
		if ((*itb)->owner == 'p' && (*itb)->present == true) //���� ���� �������� ����� � ��� ������������ �� �����
			(*itb)->update(Map, time, Player.t_x, Player.t_y, Player.t_dir); //��������� ���� � ������������ ������
		if ((*itb)->owner == 'e' && (*itb)->present == true) //���� ���� �������� ���� � ��� ������������ �� �����
			for (ite = Enemies.begin(); ite != Enemies.end(); ite++) //���������� �� ������ ������
			{
				(*itb)->update(Map, time / 4, (*ite)->t_x, (*ite)->t_y, (*ite)->t_dir); //��������� ���� � ������������ �����
			}
	}

	if (Player.life) //���� ����� ���
	{
		Player.update(time, Map); //��������� ���
		Player.timeBeforeShot += time; //��������� ����� �� �������� 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) //���� ������ ������
		{
			if (Player.timeBeforeShot > 500) //���� ����� �� ������� ����������
			{
				Bullets.push_back(new bullet(Player.t_x + 24, Player.t_y + 32, 'p', Player.t_dir)); //���������� � ��������� ������-����
				itb = Bullets.end(); //��������� �� ����� ������
				itb--; //��������� �� ������������� ����
				(*itb)->update(Map, time, Player.t_x, Player.t_y, Player.t_dir); //��������� �
				(*itb)->present = true; //������������
				Player.timeBeforeShot = 0; //�������� ����� �� ��������
			}
		}
	}


	for (ite = Enemies.begin(); ite != Enemies.end(); ite++) //���� �� ������ ������
	{
		if ((*ite)->life) //���� ���� ���
		{
			(*ite)->update(time, Map); //��������� ���
			(*ite)->timeBeforeShot += time; //��������� ����� �� �������� 

			if ((*ite)->timeBeforeShot > 1000) //���� ���� �� ������� �������
			{
				if (rand() % 2) //�������� �������� ������ ��� ����, ���� 1
				{
					Bullets.push_back(new bullet((*ite)->t_x, (*ite)->t_y, 'e', (*ite)->t_dir)); //���������� � ��������� ������-����
					itb = Bullets.end(); //��������� �� ����� ������
					itb--; //��������� �� ������������� ����
					(*itb)->update(Map, time, (*ite)->t_x, (*ite)->t_y, (*ite)->t_dir); //��������� �
					(*itb)->present = true; //������������
				}
			(*ite)->timeBeforeShot = 0; //�������� ����� �� ��������
			}

			if ((*ite)->t_Sprite.getGlobalBounds().intersects(Player.t_Sprite.getGlobalBounds())) //���� ������ ����� ������������ �� �������� ������
				Player.collapse(); //����� ����

			for (itb = Bullets.begin(); itb != Bullets.end(); itb++) //���������� �� ������ ����
			{
				if ((*itb)->b_Sprite.getGlobalBounds().intersects(Player.t_Sprite.getGlobalBounds()) && (*itb)->owner == 'e') //���� ��������� ���� � ������ ���� ��������� �� �������� ������
				{
					Player.collapse(); //����� ����
					(*itb)->present = false; //���� �����������
				}

				if ((*itb)->b_Sprite.getGlobalBounds().intersects(Tower.mSprite.getGlobalBounds())) //������ ���� ��������� �� �������� �����
				{
					Tower.life = false; //���������� �����
					gameOver = true; //���� ��������
				}

				if ((*itb)->b_Sprite.getGlobalBounds().intersects((*ite)->t_Sprite.getGlobalBounds()) && (*itb)->owner == 'p') //���� ��������� ����� � ������ ���� ��������� �� �������� �����
				{
					(*ite)->collapse(); //���� ����
					(*itb)->present = false; //���� �����������
				}
			}
		}
	}
}

void game::render() //����������� ������� ���������� ����, � ������� �������� ������� ����
{
	Window.clear(); //������� ����
	Map.draw(Window); //������ �����
	if (Player.life) //���� ����� ���
		Window.draw(Player.t_Sprite); //������ ������

	for (itb = Bullets.begin(); itb != Bullets.end(); itb++) //���������� �� ������ ����
	if ((*itb)->present) //���� ���� ������������
		Window.draw((*itb)->b_Sprite); //������

	for (ite = Enemies.begin(); ite != Enemies.end(); ite++) //���������� �� ������ ������
	{ 
		if ((*ite)->life) //���� ���� ���
			Window.draw((*ite)->t_Sprite); //������
	}

	if (Tower.life) //���� ����� �� ����������
		Window.draw(Tower.mSprite);  //������

	if (!gameStarted) //���� ���� �� �������� 
		msgStart.print(Window); //������� ��������� � ������ ����

	if (gameOver) //���� ���� ��������
	{
		msgOver.print(Window); //������� ��������� �� ��������� ����

		if (!Tower.life || !Player.life) //���� ����� ���������� ��� ���� �����
			msgLost.print(Window); //������� ��������� � ���������
		if (frags == 4) //���� ����� ���� ���� �������� �����������
			msgWon.print(Window); //������� ��������� � ������
	} 

	Window.display(); //���������� ��������� � ����
}