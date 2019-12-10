#include <iostream>
#include <map.h>

map::map() //определение конструктора
{
	TileMap = new sf::String[HEIGHT_MAP] //создаем объект карты тайлов - каждый символ отвечает за различный элемент карты: w - стена-грань карты, неуничтожаема€
																													     // m - монолитный блок стены, уничтожаемый
																														 // 0 - неуничтожаемый блок стены дл€ создани€ укрытий
																														 // u - уничтожаемый блок стены дл€ соединени€ с нижним блоком d
																														 // d - уничтожаемый блок стены дл€ соединени€ с верхним блоком u
																														 // пустой блок - задний фон
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

	mTexture.loadFromFile("Textures/tileset.png"); //загружаем текстуру-тайлсет дл€ карты
	mSprite.setTexture(mTexture); //устанавливаем спрайт из текстуры
}

map::~map() //определение деструктора
{
	std::cout << "Map destroyed\n"; //проверка удалени€ объекта класса - печать в консоль
}

void map::break_wall(const int i, const int j) //определение функции разрушени€ стены - передаем в качестве еЄ аргументов еЄ координаты
{
	TileMap[i][j] = ' '; //устанавливаем текущий тайл-стену на пробел - пустой блок заднего фона
}

void map::draw(sf::RenderWindow& window) //объ€вление функции отрисовки карты
{
	for (int i = 0; i < HEIGHT_MAP; i++) //идем по строчкам
		for (int j = 0; j < WIDTH_MAP; j++) //идем по столбикам
		{
			switch (TileMap[i][j]) //в зависимости от текущего символа-тайла устанавливаем:
			{
			case ' ':
				mSprite.setTextureRect(sf::IntRect(0, 0, 64, 64)); //задний фон
				break;

			case '0':
				mSprite.setTextureRect(sf::IntRect(6 * 64, 3 * 64, 64, 64)); //неразрушаемую стенку
				break;

			case 'u':
				mSprite.setTextureRect(sf::IntRect(3 * 64, 3 * 64, 64, 64)); //разрушаемую стенку
				break;

			case 'd':
				mSprite.setTextureRect(sf::IntRect(5 * 64, 3 * 64, 64, 64)); //разрушаемую стенку
				break;

			case 'm':
				mSprite.setTextureRect(sf::IntRect(2 * 64, 3 * 64, 64, 64)); //разрушаемую стенку
				break;

			case 'w':
				mSprite.setTextureRect(sf::IntRect(7 * 64, 3 * 64, 64, 64)); //неразрушаемую стенку - край карты
				break;
			}

			mSprite.setPosition(j * 64, i * 64); //устанавливаем местоположение спрайта таким образом, потому что спрайт тайла размером 64X64
			window.draw(mSprite); //рисуем тайл
		}
}
