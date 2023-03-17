#include <SFML/Graphics.hpp>
#include <random>
#include <chrono>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const float PARTICLE_RADIUS = 2.0f;
const float RANDOM_WALK_STEP = 2.0f;
const float BROWNIAN_MOTION_STEP = 10.0f;

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Brownian Motion and Random Walk Simulation");

    sf::CircleShape particle(PARTICLE_RADIUS);
    particle.setFillColor(sf::Color::Red);
    particle.setOrigin(PARTICLE_RADIUS, PARTICLE_RADIUS);
    particle.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_real_distribution<float> randomWalkDistribution(-RANDOM_WALK_STEP, RANDOM_WALK_STEP);
    normal_distribution<float> brownianMotionDistribution(0, BROWNIAN_MOTION_STEP);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Uncomment the line below for random walk simulation
        // sf::Vector2f step(randomWalkDistribution(generator), randomWalkDistribution(generator));

        // Uncomment the line below for Brownian motion simulation
        sf::Vector2f step(brownianMotionDistribution(generator), brownianMotionDistribution(generator));

        sf::Vector2f newPosition = particle.getPosition() + step;
        newPosition.x = fmax(PARTICLE_RADIUS, fmin(newPosition.x, WINDOW_WIDTH - PARTICLE_RADIUS));
        newPosition.y = fmax(PARTICLE_RADIUS, fmin(newPosition.y, WINDOW_HEIGHT - PARTICLE_RADIUS));
        particle.setPosition(newPosition);

        window.clear(sf::Color::Black);
        window.draw(particle);
        window.display();
    }

    return 0;
}
