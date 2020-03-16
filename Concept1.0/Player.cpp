#include "Player.hpp"

Player::Player(std::string name, std::string image): _name(name), _image(image)
{
	if (!_texture.loadFromFile(image))
		exit(EXIT_FAILURE);
	_sprite.setTexture(_texture);

    _walkingAnimationDown.setSpriteSheet(_texture);
    _walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
    _walkingAnimationDown.addFrame(sf::IntRect(64, 0, 32, 32));
    _walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
    _walkingAnimationDown.addFrame(sf::IntRect(0, 0, 32, 32));

    _walkingAnimationLeft.setSpriteSheet(_texture);
    _walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
    _walkingAnimationLeft.addFrame(sf::IntRect(64, 32, 32, 32));
    _walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
    _walkingAnimationLeft.addFrame(sf::IntRect(0, 32, 32, 32));

    _walkingAnimationRight.setSpriteSheet(_texture);
    _walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
    _walkingAnimationRight.addFrame(sf::IntRect(64, 64, 32, 32));
    _walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
    _walkingAnimationRight.addFrame(sf::IntRect(0, 64, 32, 32));

    _walkingAnimationUp.setSpriteSheet(_texture);
    _walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
    _walkingAnimationUp.addFrame(sf::IntRect(64, 96, 32, 32));
    _walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
    _walkingAnimationUp.addFrame(sf::IntRect(0, 96, 32, 32));

    _currentAnimation = &_walkingAnimationDown;

    // set up AnimatedSprite
    _animatedSprite = AnimatedSprite(sf::seconds(0.2), true, true);
    _animatedSprite.setPosition(sf::Vector2f(sf::Vector2i(1920, 1080) / 2));
}

Player::~Player()
{
}

sf::Sprite &Player::getSprite()
{
	return _sprite;
}

sf::Texture& Player::getTexture()
{
	return _texture;
}

AnimatedSprite& Player::getAnimatedSprite()
{
    return _animatedSprite;
}

void Player::keyInputs(float &speed, bool &noKeyWasPressed, sf::Time *frameTime)
{
    sf::Vector2f movement(0.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
        _currentAnimation = &_walkingAnimationLeft;
        movement.x -= speed;
        noKeyWasPressed = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
        _currentAnimation = &_walkingAnimationRight;
        movement.x += speed;
        noKeyWasPressed = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
        _currentAnimation = &_walkingAnimationUp;
        movement.y -= speed;
        noKeyWasPressed = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
        _currentAnimation = &_walkingAnimationDown;
        movement.y += speed;
        noKeyWasPressed = false;
	}

    _animatedSprite.play(*_currentAnimation);
    _animatedSprite.move(movement * frameTime->asSeconds());

    // if no key was pressed stop the animation
    if (noKeyWasPressed)
    {
        _animatedSprite.stop();
    }
    noKeyWasPressed = true;

    // update AnimatedSprite
    _animatedSprite.update(*frameTime);
}