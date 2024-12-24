#include"Bat.h"
#include<SFML/Graphics.hpp>
#include<sstream>
int main()
{
	sf:RenderWindow window(VideoMode(720, 480), "Pong");

	int score = 0;

	int lives = 0;

	Bat bat(720 / 2, 480-20);

	Text hud;

	Font font;

	font.loadFromFile("E:/Work/Projects/C++Projects/VisualStudioProjects/Github1/Pong/Pong/Pong/fonts/DS-DIGIT.TTF");

	hud.setFont(font);

	hud.setCharacterSize(50);

	hud.setFillColor(Color::White);

	hud.setPosition(20,20);

	Clock clock;

	while (window.isOpen())
	{
		Event event;
		
		while (window.pollEvent(event))
		
		{
			if (event.type == Event::Closed)
			
			{
				window.close();
			}
		
		}
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			
			{
				window.close();
			}
			
			if (Keyboard::isKeyPressed(Keyboard::Left))
			
			{
				bat.moveLeft();
			}
			
			else
			
			{
				bat.stopLeft();
			}
			
			if (Keyboard::isKeyPressed(Keyboard::Right))
			
			{
				bat.moveRight();
			}
			
			else
			
			{
				bat.stopRight();
			}

			Time dt = clock.restart();

			bat.update(dt);
			
			std::stringstream ss;
			
			ss << "Score:" << score << " Lives:"<<lives;
			
			hud.setString(ss.str());

			window.clear();

			window.draw(hud);

			window.draw(bat.getShape());

			window.display();
	}
	

	return 0;
}