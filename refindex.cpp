#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

using namespace std;

const double PI = 3.14159265358979323846;

double degreesToRadians(double degrees) {
    return degrees * PI / 180.0;
}

int main() {
    int windowWidth = 800;
    int windowHeight = 600;
    double n1, n2;

    cout << "Enter the refractive index of medium 1: ";
    cin >> n1;
    cout << "Enter the refractive index of medium 2: ";
    cin >> n2;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Total Internal Reflection Demonstration");

    sf::RectangleShape incidentRay(sf::Vector2f(5.0f, 200.0f));
    incidentRay.setFillColor(sf::Color::Red);
    incidentRay.setPosition(400, 300);
    incidentRay.setOrigin(2.5, 0);

    sf::RectangleShape refractedRay(sf::Vector2f(5.0f, 200.0f));
    refractedRay.setFillColor(sf::Color::Green);
    refractedRay.setPosition(400, 300);
    refractedRay.setOrigin(2.5, 0);

    sf::RectangleShape reflectedRay(sf::Vector2f(5.0f, 200.0f));
    reflectedRay.setFillColor(sf::Color::Yellow);
    reflectedRay.setPosition(400, 300);
    reflectedRay.setOrigin(2.5, 0);

    double angleStep = 0.5;
    double currentAngle = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color(50, 50, 50));

        double sinTheta2 = n1 * sin(degreesToRadians(currentAngle)) / n2;
        double criticalAngle = asin(n2 / n1) * 180.0 / PI;

        if (sinTheta2 <= 1) {
            double theta2 = asin(sinTheta2) * 180.0 / PI;
            refractedRay.setRotation(-theta2);
        }

        if (currentAngle >= criticalAngle) {
            reflectedRay.setRotation(currentAngle);
        } else {
            reflectedRay.setRotation(0);
            reflectedRay.setSize(sf::Vector2f(0, 0));
        }

        incidentRay.setRotation(currentAngle);

        window.draw(incidentRay);
        window.draw(refractedRay);
        window.draw(reflectedRay);

        window.display();

        currentAngle += angleStep;
        if (currentAngle > 90) {
            currentAngle = 0;
        }

        sf::sleep(sf::milliseconds(50));
    }

    return 0;
}
