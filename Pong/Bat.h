#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;

class Bat {
	Vector2f bat_position;
	RectangleShape bat_shape;
	float bat_Speed;
	bool bat_moving_Right=false;
	bool bat_moving_left = false;
public:
	Bat(float startX, float startY);
	FloatRect getposition();
	RectangleShape getShape();
	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();
	void update(Time dt)
};