#include "../../Sources/Headers/ParticleSystem.h"



ParticleSystem::ParticleSystem() {
	// Initialize particles
	for (int i = 0; i < 8; ++i) {
		particles.emplace_back();
	}
}

void ParticleSystem::update(float dt, Player& joueur) {
	for (Particle& particle : particles) {
		particle.update(dt, joueur);
	}
}

void ParticleSystem::draw(sf::RenderWindow& window) {
	for (Particle& particle : particles) {
		particle.draw(window);
	}
}