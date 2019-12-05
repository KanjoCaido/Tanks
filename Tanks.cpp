#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

////////////////////////////КЛАСС ПУЛИ//////////////////////// 
class Bullet {
private:
	float mX, mY, mDx, mDy;
	int mDir;

	sf::Texture mTexture;

public:
	bool present; // is it shot ?
	float timeBeforeShot;
	sf::Sprite mSprite;

	explicit Bullet(const float& x, const float& y);

	void shoot() { present = true; }
	void move(const sf::Int64& time);
	//void update(Map& map, const sf::Int64& time, float& x, const float& y, const int& dir);
	//void map_interaction(Map& map);
};

Bullet::Bullet(const float& x, const float& y)
	: present(false), mX(x), mY(y), mDir(0), mDx(0.f), mDy(0.f), timeBeforeShot(0.f) {

	mTexture.loadFromFile("Textures/bullet.png");
	mSprite.setTexture(mTexture);
	mSprite.setTextureRect(sf::IntRect(0, 0, 9, 12));
	mSprite.setPosition(x, y);
}

void Bullet::move(const sf::Int64& time) {
	switch (mDir) {
	case 0:
		mDx = 0.3f;
		mDy = 0;
		mSprite.setRotation(90.f);
		break;

	case 1:
		mDx = -0.3f;
		mDy = 0;
		mSprite.setRotation(-90.f);
		break;

	case 2:
		mDx = 0;
		mDy = 0.3f;
		mSprite.setRotation(180.f);
		break;

	case 3:
		mDx = 0;
		mDy = -0.3f;
		mSprite.setRotation(0.f);
		break;
	}

	mX += mDx * time;
	mY += mDy * time;
	mSprite.setPosition(mX, mY);
}



int main()
{
	VideoMode desktop = sf::VideoMode::getDesktopMode();
	RenderWindow window(sf::VideoMode(1024, 768, desktop.bitsPerPixel), "Tanks");
	window.setFramerateLimit(60);

	Texture herotexture; 
	herotexture.loadFromFile("Textures/tank.png"); 

	Sprite herosprite; 
	herosprite.setTexture(herotexture); 
	herosprite.setPosition(250, 250);  
	herosprite.setOrigin(32, 32);

		
	while (window.isOpen())   
	{
		Event event; 
		while (window.pollEvent(event)) 
		{
			if (event.type == Event::Closed)
				window.close(); 
		}
  
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{    
			herosprite.setTexture(herotexture);
			herosprite.move(-2.5, 0); 
			herosprite.setRotation(270);
		} 
   
		if (Keyboard::isKeyPressed(Keyboard::Right)) 
		{    
			herosprite.setTexture(herotexture);
			herosprite.move(2.5, 0); 
			herosprite.setRotation(90);
			
		} 

		if (Keyboard::isKeyPressed(Keyboard::Up) && !Keyboard::isKeyPressed(Keyboard::Left) && !Keyboard::isKeyPressed(Keyboard::Right))
		{    
			herosprite.setTexture(herotexture);
			herosprite.move(0, -2.5);
			herosprite.setRotation(0);	
		} 

		if (Keyboard::isKeyPressed(Keyboard::Down) && !Keyboard::isKeyPressed(Keyboard::Left) && !Keyboard::isKeyPressed(Keyboard::Right))
		{   
			herosprite.setTexture(herotexture);
			herosprite.move(0, 2.5); 
			herosprite.setRotation(180);
		}   

		window.clear(); 
		window.draw(herosprite); 
		window.display(); 
	}
	return 0;
}