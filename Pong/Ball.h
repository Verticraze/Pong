#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;

class Ball {

	Vector2f ballPosition;
	
	RectangleShape ballShape;

	float ballSpeed = 300.0f;
	
	float ballDirX = 0.2f;

	float ballDirY = 0.2f;

public:

	Ball(float startX, float startY);

	FloatRect getPosition();
	
	RectangleShape getShape();
	
	float getXVelocity();
	
	void ReboundSides();
	
	void ReboundBatOrTop();
	
	void ReboundBottom();
	
	void update(Time dt);
};