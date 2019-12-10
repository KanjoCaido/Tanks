#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class map; //����� �����, ���������� ��� ������� �������������� � ������

class tank  //����� �����, ������ ������� ������ � ������-�����������
{
protected:
	float t_dx, t_dy, t_Speed, t_CurrentFrame; //���������� ���������� �� ���� � ������, �������� �������� �����, �������� ����� �����

	sf::String t_File; //���� � ��������� �����
	sf::Texture t_Texture; //�������� �����

public:
	tank(const float x, const float y, const sf::String file); //���������� ������������ � ����������� - ������������ ����� � ��� ���������

	virtual ~tank(); //���������� ������������ ����������� - ������ ��� ������

	float t_x, t_y; //���������� �����
	bool life; //��������� ����������, ���������� �� ��, ��������� ���� ������, ��� ���

	enum TDIR //������������ ����������� �������� �����
	{ 
		left = 0, 
		right = 1, 
		up = 2, 
		down = 3
	} t_dir;

	sf::Sprite t_Sprite; //������ �����

	void animate(const sf::Int64 time); //���������� ������� � ��������� �����, � �������� ��������� ����� ����

	void collapse(); //���������� �������-����������� �����

	virtual void move(const sf::Int64 time) //����������� ������� ����������� �����, ��������������� � ��������
	{

	}
	
	void map_interaction(map& map); //���������� �������-�������������� ����� � ������
};