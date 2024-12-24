
#include"Bat.h"

Bat::Bat(float startX, float startY) :batPosition(startX, startY)
{
	batShape.setSize(sf::Vector2f(100,5));

	batShape.setPosition(batPosition);
}

FloatRect Bat::getPosition()
{
	return batShape.getGlobalBounds();
}

RectangleShape Bat::getShape()
{
	return batShape;
}

void Bat::moveLeft()
{
	batMovingLeft = true;
}
void Bat::moveRight()
{
	batMovingRight = true;
}
void Bat::stopLeft()
{
	batMovingLeft = false;
}
void Bat::stopRight()
{
	batMovingRight = false;
}
void Bat::update(Time dt)
{
	if (batMovingLeft)
	{
		batPosition.x -= batSpeed * dt.asSeconds();
	}
	if (batMovingRight)
	{
		batPosition.x += batSpeed * dt.asSeconds();
	}
	batShape.setPosition(batPosition);
}