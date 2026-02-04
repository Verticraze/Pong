
#include "pong_bat.h"
using namespace sf;

// This the constructor and it is called when we create an object
pong_bat::pong_bat(float startX, float startY)
{
    position.x = startX;
    position.y = startY;
 
    batShape.setSize(sf::Vector2f(50, 5));
    batShape.setPosition(position);
}

sf::FloatRect pong_bat::getPosition()
{
    return batShape.getGlobalBounds();
}
 
sf::RectangleShape pong_bat::getShape()
{
    return batShape;
}
 
void pong_bat::moveLeft()
{
    position.x -= batSpeed;
}
 
void pong_bat::moveRight()
{
    position.x += batSpeed;
}
 
void pong_bat::update()
{
    batShape.setPosition(position);
}
