#include <iostream>
#include <tower.h>

tower::tower():life(true)  //����������� ������������, ������������� life
{
	mTexture.loadFromFile("Textures/tower.png"); //��������� �������� ����� �� ����� Textures, ����� tower.png
	mSprite.setTexture(mTexture); //������������� ������ �� ��������
	mSprite.setPosition(576, 832); //������������� � ������� �� �����
}

tower::~tower() //����������� ����������� 
{
	std::cout << "Tower destroyed\n"; //�������� �������� ������� ������ - ������ � �������
}