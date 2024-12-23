#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "act 2");
	window.setFramerateLimit(60);
	sf::Vector2f position(0.0f, 100.0f);
	sf::Vector2f velocity(10.0f, 0.0f);
		float acceleration = 10;
	while (window.isOpen())
	{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {
					window.close();
				}
				if (event.type == sf::Event::KeyPressed) {
					if (event.key.code == sf::Keyboard::Right) {
						acceleration += 20;
					}
					if (event.key.code == sf::Keyboard::Left) {
						acceleration -= 20;
					}
				}
			}
			float deltaTime = 0.1f / 60.0f; 
			velocity.x += acceleration * deltaTime; 
			position.x += velocity.x * deltaTime; 
			window.clear();

			sf::RectangleShape object(sf::Vector2f(50.0f, 50.0f)); 
			object.setPosition(position);
			object.setFillColor(sf::Color::Magenta);
			window.draw(object);
			window.display();
	}
	return 0;
}


