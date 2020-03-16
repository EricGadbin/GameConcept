#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Player {
public:
	Player(std::string name, std::string image);
	~Player();

	sf::Sprite &getSprite();
	void keyInputs();
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	std::string _name;
	std::string _image;

};