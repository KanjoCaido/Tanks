#include <iostream>
#include <message.h>

message::message(const float x, const float y, const sf::String str): go_x(x), go_y(y) 
//определение конструктора, передаем с его помощью координаты сообщения и текстовую строку с сообщением
{
	go_Font.loadFromFile("Font/prstart.ttf"); //загружаем шрифт из папки Font, файла prstart.ttf
	go_Str.setFont(go_Font); //устанавиваем шрифт текста
	go_Str.setString(str); //устанавливаем строку сообщения
	go_Str.setPosition(go_x, go_y); //устанавливаем координаты сообщения
	go_Str.setCharacterSize(40); //устанавливаем размер шрифта
}

message::~message() //определение деструктора
{
	std::cout << "Game-related message destroyed\n"; //проверка удаления объекта класса - печать в консоль
}