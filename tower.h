#pragma once
#include <SFML/Graphics.hpp>

class tower  //����� �����, ������� �� ��������
{
private:
	sf::Texture mTexture; //� ��������

public:
	sf::Sprite mSprite; //� ������
	bool life; //��������� ����������, ���������� �� ��, ���������� ���, ��� ���

	tower(); //���������� � ������������ ��� ����������
	~tower(); //���������� �����������
};