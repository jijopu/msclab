#include <iostream>
#include <cmath>

const double PI = 3.14159265;

// Function to simulate damped harmonic motion
void dampedHarmonicMotion(double m, double k, double c, double x0, double v0, double dt, double tmax) {
    double t = 0.0;
    double x = x0;
    double v = v0;
    double omega = sqrt(k/m);
    double gamma = c/(2.0*m);
    double A = sqrt(x0*x0 + (v0 + gamma*x0/omega)*(v0 + gamma*x0/omega)/omega/omega);

    std::cout << "t\t\tx" << std::endl;

    while (t <= tmax) {
        x = A * exp(-gamma*t) * cos(omega*sqrt(1.0-gamma*gamma)*t);
        std::cout << t << "\t" << x << std::endl;
        t += dt;
    }

    // Calculate damping coefficient, relaxation time, and Q-factor
    double alpha = gamma*omega;
    double beta = sqrt(1.0 - gamma*gamma);
    double wd = omega*beta;
    double wd0 = omega*sqrt(1.0 - alpha*alpha);
    double wd1 = wd0*sqrt(1.0 - beta*beta);
    double xi = alpha/beta;
    double tau = 1.0/gamma;
    double q = wd/2.0/gamma;
    
    std::cout << "Damping coefficient: " << gamma << std::endl;
    std::cout << "Relaxation time: " << tau << std::endl;
    std::cout << "Q-factor: " << q << std::endl;
}

int main() {
    double m, k, c, x0, v0, dt, tmax;

    // Input parameters
    std::cout << "Enter mass (kg): ";
    std::cin >> m;
    std::cout << "Enter spring constant (N/m): ";
    std::cin >> k;
    std::cout << "Enter damping coefficient (Ns/m): ";
    std::cin >> c;
    std::cout << "Enter initial displacement (m): ";
    std::cin >> x0;
    std::cout << "Enter initial velocity (m/s): ";
    std::cin >> v0;
    std::cout << "Enter time step (s): ";
    std::cin >> dt;
    std::cout << "Enter maximum time (s): ";
    std::cin >> tmax;

    // Simulate damped harmonic motion and find parameters
    dampedHarmonicMotion(m, k, c, x0, v0, dt, tmax);

    return 0;
}
