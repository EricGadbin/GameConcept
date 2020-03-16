#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.hpp"
#include "AnimatedSprite.hpp"

class GameScene {
public:
	GameScene(Player *player);
	~GameScene();
	int setMusic(std::string musicName);
	sf::Music &getMusic();
	void setBackground(std::string background);
	sf::Sprite &getBackground();
	int loop(sf::RenderWindow* window);
private:
	Player* _player;
	sf::Music _music;
	sf::Event _event;
	sf::Sprite _background;
	sf::Texture _backgroundTexture;

};