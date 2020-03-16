#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.hpp"
#include "GameScene.hpp"


int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game");
	Player player1("Robin", "train.jpg");
	GameScene mainGame(&player1);

	mainGame.setMusic("trainSong.ogg");
	mainGame.loop(&window);
	return 0;
}