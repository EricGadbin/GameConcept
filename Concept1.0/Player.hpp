#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "AnimatedSprite.hpp"

class Player {
public:
	Player(std::string name, std::string image);
	~Player();

	sf::Sprite& getSprite();
	sf::Texture &getTexture();
	AnimatedSprite& getAnimatedSprite();
	void keyInputs(float& speed, bool& noKeyWasPressed, sf::Time *frameTime);
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	std::string _name;
	std::string _image;
	Animation _walkingAnimationDown;
	Animation _walkingAnimationUp;
	Animation _walkingAnimationLeft;
	Animation _walkingAnimationRight;
	Animation* _currentAnimation;
	AnimatedSprite _animatedSprite;

};