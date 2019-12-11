#pragma once
#include <SFML/Graphics.hpp>

class message //класс сообщени€ о состо€нии игры
{
private:
	float go_x, go_y; //координаты сообщени€ на экране

	sf::Font go_Font; //шрифт
	sf::Text go_Str; //строка текста

public:
	message(const float x, const float y, const sf::String str); //объ€вление конструктора с параметрами

	~message(); //объ€вление деструктора

	void print(sf::RenderWindow &window) //функци€ вывода на экран сообщени€, в качестве аргумента использует адрес объекта 'window' дл€ использовани€ его метода 'draw'
	{ 
		window.draw(go_Str); //соответственно вывод
	}
};
