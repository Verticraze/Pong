#include "Ball.h"
Ball::Ball(float startX, startY) :ball_Position(startX,startY)
{
	ballShape.
}
FloatRect Ball::getPosition()
{
	return ballShape.getGlobalBounds();
}

RectangleShape Ball::getShape()
{
	return ballShape;
}

float Ball::getXVelocity()
{
	return ballDirX;
}

void Ball :: ReboundSides()
{
	ballDirX = -ballDirX;
}

void Ball::ReboundBatOrTop()
{
	ballDirY = -ballDirY;
}

void Ball::ReboundBottom()
{
	ballPosition.y = 0;

	ballPosition.x = 500;

	ballDirY = -ballDirY;
}

void Ball::update(Time dt)
{
	ballPosition.y += ballDirX * ballSpeed * dt.asSeconds();

	ballPosition.x = ballDirX * ballSpeed * dt.asSeconds();

	ballShape.setPosition(ballPosition);
}