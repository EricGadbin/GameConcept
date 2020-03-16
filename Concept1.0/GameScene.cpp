
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
	_music.setVolume(0);
	_music.play();
	return 0;
}

sf::Music &GameScene::getMusic()
{
	return _music;
}

int GameScene::loop(sf::RenderWindow *window)
{
	while (window->isOpen())
	{
		_player->keyInputs();
		while (window->pollEvent(_event))
		{
			if (_event.type == sf::Event::Closed)
			{
				window->close();
			}
		}
		window->clear();
		window->draw(_player->getSprite());
		window->display();
	}
	return 0;
}
