#pragma once
#include <SFML/Window.hpp>
#include <tank.h>

class player : public tank //����� ������ - ��������� ���� � ������ ������ ����� � ������������� ������� public
{
public:
	player(); //���������� ������������ ��� ����������

	~player(); //���������� ����������� ����������

	float timeBeforeShot; //���������� - ����� �� ��������
	void move(const sf::Int64 time); //���������� �������-����������� ������
	void update(const sf::Int64 time, map& map); //���������� �������-���������� �������-������ �� ����� ���� �� �����
};