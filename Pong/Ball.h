#pragma once
#include<SFML/Graphics.hpp>
class Ball
{
private:
	sf::Vector2f ballPosition;
	sf::RectangleShape ballshape;
	float ballSpeed = 300.0f;
	float ballDirX = 0.2f;
	float ballDirY = 0.2f;
public:
	Ball(float startX, float startY);
	sf::FloatRect getPosition();
	sf::RectangleShape getShape();
	float getXVelocity();
	void ReboundSides();
	void ReboundBatOrTop();
	void ReboundBottom();
	void update(sf::Time dt);
};