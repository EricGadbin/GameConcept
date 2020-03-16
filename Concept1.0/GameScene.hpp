#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.hpp"

class GameScene {
public:
	GameScene(Player *player);
	~GameScene();
	int setMusic(std::string musicName);
	sf::Music &getMusic();
	int loop(sf::RenderWindow* window);
private:
	sf::Music _music;
	sf::Event _event;
	Player *_player;

};