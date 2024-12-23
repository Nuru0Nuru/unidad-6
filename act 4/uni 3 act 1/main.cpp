#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include "principal.h"
#include "fondo.h"
#include "npc.h"
#include "mira.h"
using namespace sf;
using namespace std;
float posX = 0;
bool jugando = false;
int puntos = 0;
clock_t tiempoInicial = clock(); 

int main() {
	Texture texF; 
	texF.loadFromFile("fondo.jpg"); 
	Texture rojo;
	rojo.loadFromFile("rcircle.png");  
	Texture Tmira;
	Tmira.loadFromFile("mira2.png");

	fondo Fondo;
	Fondo.colocarTextura(texF);
	npc circulo;
	mira Mira;
	Mira.colocarTextura(Tmira);
	Mira.setPosition(400, 300);
	Vector2f position(100.0f, 100.0f);
	Vector2f velocity(0.50f, 200.0f);
	const float acceleration = 40;


	RenderWindow Ventana(sf::VideoMode(800, 600, 32), "act 4");
	Ventana.setFramerateLimit(60); 
	puntos = 0;
	while (Ventana.isOpen()) {

		bool colision = false;
		if (!jugando) {
			posX = (rand() % 10 + 1) * 60 + 100;
			tiempoInicial = clock();
			jugando = true; 
			position.x = posX;
			position.y = 40;
			velocity.x = 4.5;
			velocity.y = 1.5;
			circulo.colocarTextura(rojo); 
		}
		Event evento;
		while (Ventana.pollEvent(evento)) {
			if (evento.type == sf::Event::Closed) {
				Ventana.close();
			}
			if (evento.type == sf::Event::MouseButtonPressed && evento.mouseButton.button == sf::Mouse::Left) {
				if (circulo.pegar(Ventana)) {
					puntos++;
					jugando = false;
					std::cout << "Puntos: " << puntos << endl;
				}
			}
		}
		float deltaTime = 0.1f / 60.0f;
		velocity.y += acceleration;
		position.y += velocity.y * deltaTime;
		position.x += velocity.x;
		if (position.y > 472) {
			position.y = 472.0f;
			velocity.y = -velocity.y;
		}
		if (position.x > 672) {
			position.x = 672.0f;
			velocity.x = -velocity.x;
		}
		if (position.x < 0) {
			position.x = 0.0f;
			velocity.x = -velocity.x;
		}
		circulo.setPosition(position.x, position.y);

		Mira.actualizar(Ventana);
		Ventana.clear();
		Fondo.dibujar(Ventana); 
		circulo.dibujar(Ventana);
		Mira.dibujar(Ventana); 
		Ventana.display();
	}
	return 0;
}




