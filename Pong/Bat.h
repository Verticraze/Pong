#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;

class Bat {
	Vector2f batPosition;
	RectangleShape batShape;
	float batSpeed;
	bool batMovingRight=false;
	bool batMovingLeft = false;
public:
	Bat(float startX, float startY);
	FloatRect getPosition();
	RectangleShape getShape();
	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();
	void update(Time dt);
};