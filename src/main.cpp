#include "pong_bat.h"
#include "pong_ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
	int window_width = 1280;
	int window_height = 720;

	RenderWindow window(VideoMode(window_width, window_height), "Pong");

	int score = 0;
	int lives = 3;

	// create a bat
	pong_bat bat (window_width / 2, window_height - 20);

	// create a ball
	pong_ball ball(window_width / 2, 1);

	 // Create a "Text" object called "message". Weird but we will learn about objects soon
	Text hud;

	 // Make it really big
	hud.setCharacterSize(75);

	 // Choose a color
	hud.setFillColor(sf::Color::White);
	// This "while" loop goes round and round- perhaps forever
	while (window.isOpen()) {
		/*
			Handle the player input
			*********************************************************************
			*********************************************************************
			*********************************************************************
		*/

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				// Someone closed the window- bye
				window.close();
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			// move left...
			bat.moveLeft();
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right)) {
			// move right...
			bat.moveRight();
		}
		else if (Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			// quit...
			// Someone closed the window- bye
			window.close();
		}
		/*
		Update the frame
		*********************************************************************
		*********************************************************************
		*********************************************************************
		*/
	
		// Handle ball hitting the bottom
		if (ball.getPosition().top > window_height) {
			// reverse the ball direction
			ball.hitBottom();
	
			// Remove a life
			lives --;
	
			// Check for zero lives
			if (lives < 1) {
				// reset the score
				score = 0;
				// reset the lives
				lives = 3;
			}
		}

		// Handle ball hitting top
		if (ball.getPosition().top < 0) {	
			ball.reboundBatOrTop();
			// Add a point to the players score
			score++;
		}

		// Handle ball hitting sides
		if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > window_width) {
			ball.reboundSides();
		}

		// Has the ball hit the bat?
		if (ball.getPosition().intersects(bat.getPosition())) {
			// Hit detected so reverse the ball and score a point
			ball.reboundBatOrTop();
		}
		ball.update();
		bat.update();
	
		// Update the HUD text
		std::stringstream ss;
		ss << "Score:" << score << "    Lives:" << lives;
		hud.setString(ss.str());
		 /*
				Draw the frame
		*********************************************************************
		*********************************************************************
		*********************************************************************
		*/

		// Clear everything from the last frame
		window.clear();

		window.draw(bat.getShape());
	
		window.draw(ball.getShape());

		// Draw our score
	        window.draw(hud);

		// Show everything we just drew
		window.display();

	} // This is the end of the "while" loop

	return 0;
}
