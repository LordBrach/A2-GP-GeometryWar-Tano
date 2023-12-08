#include <SFML/Graphics.hpp>
#include <vector>
#include "Particle.h"

class ParticleSystem {
public:
    ParticleSystem();

    void update(float dt, Player &joueur);
    void draw(sf::RenderWindow& window);

private:
    std::vector<Particle> particles;
};
