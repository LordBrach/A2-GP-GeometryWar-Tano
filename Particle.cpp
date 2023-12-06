#include "Particle.h"
Particle::Particle() {
	shape.setSize(sf::Vector2f(10, 10));

	velocity.x = static_cast<float>(rand() % 200 - 100);
	velocity.y = static_cast<float>(rand() % 200 - 100);
}

void Particle::update(float dt, Player& joueur) {
	shape.move(velocity * dt);
	shape.setFillColor(joueur.getColor());
	shape.setPosition(sf::Vector2f((joueur.getPosition().x) - rand() % 400, (joueur.getPosition().y + 128) - rand() % 128));
}

void Particle::draw(sf::RenderWindow& window) {
	window.draw(shape);
}
