
#include "pong_ball.h"
 
// This the constructor and it is called when we create an object
pong_ball::pong_ball(float startX, float startY)
{
    position.x = startX;
    position.y = startY;
 
    ballShape.setSize(sf::Vector2f(10, 10));
    ballShape.setPosition(position);
}

sf::FloatRect pong_ball::getPosition()
{
    return ballShape.getGlobalBounds();
}
 
sf::RectangleShape pong_ball::getShape()
{
    return ballShape;
}
 
float pong_ball::getXVelocity()
{
    return xVelocity;
}
 
void pong_ball::reboundSides()
{
    xVelocity = -xVelocity;
}
 
void pong_ball::reboundBatOrTop()
{
    position.y -= (yVelocity * 30);
    yVelocity = -yVelocity;
 
}
 
void pong_ball::hitBottom()
{
    position.y = 1;
    position.x = 500;
}
 
void pong_ball::update()
{
    // Update the ball position variables
    position.y += yVelocity;
    position.x += xVelocity;
 
    // Move the ball and the bat
    ballShape.setPosition(position);
}
