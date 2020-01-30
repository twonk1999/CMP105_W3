#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;


	// initialise game objects
	rect.setPosition(100, 100);
	rect.setSize(sf::Vector2f(50,25));

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	sf::Vector2u pos = window->getSize();
	sf::Vector2f rectPos = rect.getPosition();
	if (rect.getPosition().x+rect.getSize().x>window->getSize().x)
	{
		float x = window->getSize().x - rect.getSize().x;
		rect.setPosition(x, rect.getPosition().y);
		speed = -speed;
	}
	else if (rect.getPosition().x + rect.getSize().x < window->getSize().x - 1150)
	{
		float x = window->getSize().x + rect.getSize().x;
		rect.setPosition(x, rect.getPosition().y);
		speed = -speed;
	}
	rect.move(speed*dt, 0);

}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(rect);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}