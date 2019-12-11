#include <iostream>
#include <map.h>

map::map() //����������� ������������
{
	TileMap = new sf::String[HEIGHT_MAP] //������� ������ ����� ������ - ������ ������ �������� �� ��������� ������� �����: w - �����-����� �����, ��������������
																													     // m - ���������� ���� �����, ������������
																														 // 0 - �������������� ���� ����� ��� �������� �������
																														 // u - ������������ ���� ����� ��� ���������� � ������ ������ d
																														 // d - ������������ ���� ����� ��� ���������� � ������� ������ u
																														 // ������ ���� - ������ ���
	{
		"wwwwwwwwwwwwwwwwwww",
		"w   u   m0m   u   w",
		"w  m0m       m0m  w",
		"wu  d  m0 0m  d  uw",
		"wd      d d      dw",
		"w0m u         u m0w",
		"wd  0m  m0m  m0  dw",
		"w   d         d   w",
		"w      0m m0      w",
		"w u  u u   u u  u w",
		"w d0 d d 0 d d 0d w",
		"w 0u           u0 w",
		"w  d  u mmm u  d  w",
		"w     d m m d     w",
		"wwwwwwwwwwwwwwwwwww",
	};

	mTexture.loadFromFile("Textures/tileset.png"); //��������� ��������-������� ��� �����
	mSprite.setTexture(mTexture); //������������� ������ �� ��������
}

map::~map() //����������� �����������
{
	std::cout << "Map destroyed\n"; //�������� �������� ������� ������ - ������ � �������
}

void map::break_wall(const int i, const int j) //����������� ������� ���������� ����� - �������� � �������� � ���������� � ����������
{
	TileMap[i][j] = ' '; //������������� ������� ����-����� �� ������ - ������ ���� ������� ����
}

void map::draw(sf::RenderWindow& window) //���������� ������� ��������� �����
{
	for (int i = 0; i < HEIGHT_MAP; i++) //���� �� ��������
		for (int j = 0; j < WIDTH_MAP; j++) //���� �� ���������
		{
			switch (TileMap[i][j]) //� ����������� �� �������� �������-����� �������������:
			{
			case ' ':
				mSprite.setTextureRect(sf::IntRect(0, 0, 64, 64)); //������ ���
				break;

			case '0':
				mSprite.setTextureRect(sf::IntRect(6 * 64, 3 * 64, 64, 64)); //������������� ������
				break;

			case 'u':
				mSprite.setTextureRect(sf::IntRect(3 * 64, 3 * 64, 64, 64)); //����������� ������
				break;

			case 'd':
				mSprite.setTextureRect(sf::IntRect(5 * 64, 3 * 64, 64, 64)); //����������� ������
				break;

			case 'm':
				mSprite.setTextureRect(sf::IntRect(2 * 64, 3 * 64, 64, 64)); //����������� ������
				break;

			case 'w':
				mSprite.setTextureRect(sf::IntRect(7 * 64, 3 * 64, 64, 64)); //������������� ������ - ���� �����
				break;
			}

			mSprite.setPosition(j * 64, i * 64); //������������� �������������� ������� ����� �������, ������ ��� ������ ����� �������� 64X64
			window.draw(mSprite); //������ ����
		}
}
