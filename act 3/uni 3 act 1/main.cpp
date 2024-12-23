#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "act 3");
	window.setFramerateLimit(60);
	sf::Vector2f position(400.0f, 50.0f); 
	sf::Vector2f velocity(0.0f, 100.0f); 
	const float acceleration = 98;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		float deltaTime = 0.1f / 60.0f; 
		velocity.y += acceleration;
		position += velocity * deltaTime;
		if (velocity.y > 0.0f && position.y > 560.0f)
		{
			velocity.y = -velocity.y;
		}
		window.clear();
		sf::CircleShape object(20.0f);
		object.setPosition(position);
		object.setFillColor(sf::Color::Green);
		window.draw(object);
		window.display();
	}
	return 0;
}



