#include <SFML/Graphics.hpp>
#include <cmath>

const double G = 6.67430e-11;
const double SUN_MASS = 1.989e30;
const double TIME_STEP = 1000.0;

struct Vector2D {
    double x, y;

    Vector2D operator+(const Vector2D& other) const {
        return {x + other.x, y + other.y};
    }

    Vector2D operator-(const Vector2D& other) const {
        return {x - other.x, y - other.y};
    }

    Vector2D operator*(double scalar) const {
        return {x * scalar, y * scalar};
    }
};

Vector2D calculateAcceleration(const Vector2D& position) {
    double r = std::sqrt(position.x * position.x + position.y * position.y);
    double a = -G * SUN_MASS / (r * r);
    return {position.x * a / r, position.y * a / r};
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Kepler's Laws Simulation");

    Vector2D planetPosition = {1.496e11, 0.0};
    Vector2D planetVelocity = {0.0, 29.29e3};
    Vector2D planetAcceleration = calculateAcceleration(planetPosition);

    sf::CircleShape sun(10.0f);
    sun.setFillColor(sf::Color::Yellow);
    sun.setOrigin(10.0f, 10.0f);
    sun.setPosition(400.0f, 400.0f);

    sf::CircleShape planet(4.0f);
    planet.setFillColor(sf::Color::Blue);
    planet.setOrigin(4.0f, 4.0f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        Vector2D newPosition = planetPosition + planetVelocity * TIME_STEP + planetAcceleration * (0.5 * TIME_STEP * TIME_STEP);
        Vector2D newAcceleration = calculateAcceleration(newPosition);
        Vector2D newVelocity = planetVelocity + 0.5 * (planetAcceleration + newAcceleration) * TIME_STEP;

        planetPosition = newPosition;
        planetVelocity = newVelocity;
        planetAcceleration = newAcceleration;

        planet.setPosition(planetPosition.x * 1.0e-9 + 400.0, -planetPosition.y * 1.0e-9 + 400.0);

        window.clear(sf::Color::Black);
        window.draw(sun);
        window.draw(planet);
        window.display();
    }

    return 0;
}
