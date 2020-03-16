#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game");
	sf::Event event;
	sf::Texture texture;
	if (!texture.loadFromFile("train.jpg"))
		return EXIT_FAILURE;
	sf::Sprite sprite(texture);
	sf::Music music;
	if (!music.openFromFile("trainSong.ogg"))
		return EXIT_FAILURE;

	music.setLoop(true);
	music.setVolume(5);
	music.play();

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

		}
		window.clear();
		window.draw(sprite);
		window.display();
	}
	return (0);
}