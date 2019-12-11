#pragma once
#include <SFML/Graphics.hpp>
#include <map.h>
#include <player.h>
#include <enemy.h>
#include <tower.h>
#include <message.h>
#include <list>

class game //����� ����
{
private:
	bool gameOver; //��������� ����������-��������� ���� (���������/�� ���������)
	bool gameStarted; //��������� ����������-������ ���� (������/�� ������)

	int frags; //����������, � ������� ����������� ���������� ������������ ������� ������-������

	sf::RenderWindow Window; //������ Window ������ RenderWindow, � ������� ����� �������������� ���� ����
	tower Tower; //������-�����
	map Map; //������-�����
	player Player; //������-�����

	std::list<enemy*> Enemies; //������ � �������
	std::list<enemy*>::iterator ite; //�������� ��� ������ � ���� �������

	std::list<bullet*> Bullets; //������ � ������ 
	std::list<bullet*>::iterator itb; //�������� ��� ������ � ���� �������

	int ex[4] = { 64 , 1088 , 64 , 1088 }; //������ ��������� ������ �� x
	int ey[4] = { 64 , 65 , 448 , 448 }; //������ ��������� ������ �� y

	message msgStart; //������-��������� � ������ ����
	message msgOver; //������-��������� � ����� ����
	message msgLost; //������-��������� � ��������� ����
	message msgWon; //������-��������� � �������� ����

public:
	game(); //���������� ������������ ��� ����������

	~game(); //���������� �����������

	void elist() //�������, � ������� ����������� ������ ������� � ������������ �� �������
	{
		for (int i = 0; i < 4; i++) //4 �����
			Enemies.push_back(new enemy(ex[i], ey[i])); //���������� ��������������� � ����� ������
	}

	void process_events(); //���������� ������� ��������� �������
	void update(const sf::Int64 time); //���������� ������� ���������� ����
	void render(); //���������� ������� ���������� ����, � ������� �������� ������� ����
};
