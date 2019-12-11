#pragma once
#include <tank.h>

class enemy : public tank //����� ����� - ��������� ���� � ������ ������ ����� � ������������� ������� public
{
public:
	enemy(const float x, const float y); //���������� ������������ � ����������� - ������������
	enemy(const enemy& enemy) : enemy(enemy.t_x, enemy.t_y) //����������� ����������� - ��� ����������� �������, �������� ���������� �����	
	{

	}

	~enemy(); //���������� ����������� ����������

	float timeBeforeMoving; //���������� - ����� �� ����� ����������� ��������
	float timeBeforeShot; //���������� - ����� �� ��������

	void move(const sf::Int64 time); //���������� �������-����������� �����
	void update(const sf::Int64 time, map& map); //���������� �������-���������� �������-����� �� ����� ���� �� �����
};
