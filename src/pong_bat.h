#pragma once
#include<SFML/Graphics.hpp>
class pong_bat
{
	private:
		sf::Vector2f position;
 
		// A RectangleShape object
		sf::RectangleShape batShape;
 
		float batSpeed = .3f;
 
	public:
		pong_bat(float startX, float startY);
 
		sf::FloatRect getPosition();
 
		sf::RectangleShape getShape();
 
		void moveLeft();
 
		void moveRight();
 
		void update();
};
