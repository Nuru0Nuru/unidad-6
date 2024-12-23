#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
int main()
{
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "act 1");
	window.setFramerateLimit(60);
		// Definir la posici�n y velocidad inicial del objeto
	sf::Vector2f position(0.0f, 100.0f);
	sf::Vector2f velocity(3.0f, 0.0f); // Velocidad inicial en el eje y (MRUV hacia arriba)
	sf::Vector2f velocityFinal(15.0f, 0.0f); //velocidad final x 
		// Constante de aceleraci�n para el MRUV (gravedad)
		const float acceleration = 0.5;
	
	while (window.isOpen()&& velocity.x < velocityFinal.x)
	{
		while (position.x < 800)
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			// Actualizar la velocidad del objeto en funci�n de la aceleraci�n y el tiempo transcurrido
			float deltaTime = 0.1f / 60.0f; // Suponemos que el juego se est� ejecutando a 60 FPS
			// Actualizar la posici�n del objeto en funci�n de la velocidad y el tiempo transcurrido
			position += velocity;
			// Comprobar si el objeto ha alcanzado su altura m�xima (velocidad invertida)
			window.clear();

			sf::CircleShape object(40.0f);
			object.setPosition(position);
			object.setFillColor(sf::Color::Magenta);
			window.draw(object);

			window.display();
		}
		//resestear la posicion en x
		position.x = 0;
		//aumentar la velocidad enn funcion de la aceleracion
		velocity.x += acceleration;
	}
	return 0;
}


