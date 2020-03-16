#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.hpp"
#include "GameScene.hpp"
#include "AnimatedSprite.hpp"


int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080, 32), "Game");
    window.setFramerateLimit(60);
	Player player1("Pokemon", "character1SpriteSheet.png");
	GameScene mainGame(&player1);
    mainGame.setMusic("celeste.ogg");
    mainGame.setBackground("background.png");
    mainGame.loop(&window);

	return 0;
}