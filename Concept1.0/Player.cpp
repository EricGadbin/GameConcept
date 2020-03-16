#include "Player.hpp"

Player::Player(std::string name, std::string image): _name(name), _image(image)
{
	if (!_texture.loadFromFile(image))
		exit(EXIT_FAILURE);
	_sprite.setTexture(_texture);
}

Player::~Player()
{
}

sf::Sprite &Player::getSprite()
{
	return _sprite;
}

void Player::keyInputs()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		_sprite.move(-1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		_sprite.move(1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		_sprite.move(0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		_sprite.move(0.f, 1.f);
	}
}