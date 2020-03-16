
#include "GameScene.hpp"

GameScene::GameScene(Player *player): _player(player)
{
}

GameScene::~GameScene()
{
}

int GameScene::setMusic(std::string musicName)
{
	if (!_music.openFromFile(musicName))
		return EXIT_FAILURE;
	_music.setLoop(true);
	_music.play();
	return 0;
}

sf::Music &GameScene::getMusic()
{
	return _music;
}

int GameScene::loop(sf::RenderWindow *window)
{
    sf::Clock frameClock;

    float speed = 80.f;
    bool noKeyWasPressed = true;
	while (window->isOpen())
	{
        sf::Time frameTime = frameClock.restart();
        sf::Vector2f movement(0.f, 0.f);
		_player->keyInputs(speed, noKeyWasPressed, &frameTime);
		while (window->pollEvent(_event))
		{
			if (_event.type == sf::Event::Closed)
			{
				window->close();
			}
		}
		window->clear();
		window->draw(_background);
		window->draw(_player->getAnimatedSprite());
		window->display();
	}
	return 0;
}

void GameScene::setBackground(std::string background)
{
	_backgroundTexture.loadFromFile(background);
	_background.setTexture(_backgroundTexture);
}

sf::Sprite& GameScene::getBackground()
{
	return _background;
}
