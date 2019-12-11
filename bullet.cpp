#include <iostream>	
#include <bullet.h>
#include <map.h>

bullet::bullet(const float x, const float y, const char owner, const int bdir) : present(false), b_x(x), b_y(y), b_dx(0), b_dy(0), owner(owner)
									//определение конструктора - передаем в него начальный координаты пули, направление движения и того, кто её выстрелил
									//устанавливаем отсутствие на карте по умолчанию, приращение координат
{
	switch (owner) //если владелец:
	{
	case 'p': //игрок, то 
		std::cout << "Player "; //выводим в консоль соответствующее сообщение
		break;
	case 'e': //враг, то
		std::cout << "Enemy "; //выводим в консоль соответствующее сообщение
		break;
	}
	std::cout << "launched bullet\n"; //выводим остаток сообщения
	BDIR b_dir(static_cast<BDIR>(bdir)); //преобразуем переданную переменную-направление в тип исчисления
	b_Texture.loadFromFile("Textures/bullet.png"); //загружаем текстуру из файла в папке Textures bullet.png
	b_Sprite.setTexture(b_Texture); //устанавливаем текстуру
	b_Sprite.setPosition(x, y); //устанавливаем положение пули по переданным координатам
}

bullet::~bullet() //определение деструктора
{
	switch (owner) //если владалец:
	{
	case 'p': //игрок, то
		std::cout << "Player's "; //выводим в консоль соответствующее сообщение
		break;
	case 'e': //враг, то
		std::cout << "Enemy's "; //выводим в консоль соответствующее сообщение
		break;
	}
	std::cout << "bullet destroyed\n"; //выводим остаток сообщения, для проверки удаления объекта
}

void bullet::move(const sf::Int64 time) //определение функции-перемещения пули
{
	switch (b_dir) //если пуля направлена:
	{
	case right: //вправо, то
		b_dx = 0.3; //приращение координаты по x равно 0.3
		b_dy = 0;
		break;

	case left: //влево, то
		b_dx = -0.3; //приращение координаты по x равно -0.3
		b_dy = 0;
		break;

	case up: //вправо, то
		b_dx = 0;
		b_dy = 0.3; //приращение координаты по y равно 0.3
		break;

	case down: //вправо, то
		b_dx = 0;
		b_dy = -0.3; //приращение координаты по y равно -0.3
		break;
	}

	b_x += b_dx * time; //приращаем координату x
	b_y += b_dy * time; //приращаем координату y
	b_Sprite.setPosition(b_x, b_y); //устанавливаем спрайт по координатам пули
}

void bullet::update(map& map, const sf::Int64 time, float x, const float y, const int dir) //определение функции-обновления объекта-пули во время игры по карте
{
	if (present) //если присутствует
	{
		move(time); //перемещаем
		map_interaction(map); //взаимодействуем с картой
	}
	else //иначе
	{
		switch (dir) //взависимости от направления танка, переданного как параметр, устанавливаем направление пули
		{
		case left:
			b_dir = left; 
			break;
		case right:
			b_dir = right;
			break;
		case down:
			b_dir = up;
			break;
		case up:
			b_dir = down;
			break;
		}

		switch (b_dir) //в зависимости от направления пули меняем её начальные координаты
		{
		case right:
			b_x = x + 55;
			b_y = y + 25;
			break;

		case left:
			b_x = x + 10;
			b_y = y + 25;
			break;

		case up:
			b_x = x + 25;
			b_y = y + 55;
			break;

		case down:
			b_x = x + 25;
			b_y = y + 10;
			break;
		}
		b_Sprite.setPosition(b_x, b_y); //устанавливаем спрайт пули по её координатам
	}
}

void bullet::map_interaction(map& map) //определение функции-взаимодействия пули с картой
{
	for (int i = (b_y + 4) / 64; i < (b_y + 16 - 4) / 64; ++i) //проходим по пикселям спрайта пули построчно 
		for (int j = (b_x + 4) / 64; j < (b_x + 16 - 4) / 64; ++j) //проходим по пикселям спрайта танка по столбикам
		//поставили приращение +- 4, так как не весь спрайт 64X64 занят именно танком, есть свободное пространство
		{
			char tile = map.get_tile(i, j); //в переменную tile заносим значение тайла карты, на которой находится пиксель спрайта пули

			if (tile == 'c' || tile == 'u' || tile == 'd' || tile == 'm') //если столкнулась с разрушаемой стенкой
			{
				map.break_wall(i, j); //рушим стенку
				present = false; //убираем пулю
			}

			if (tile == 'w' || tile == '0')  //если столкнулась с неразрушаемой стенкой
				present = false; //просто убираем пулю
		}
}