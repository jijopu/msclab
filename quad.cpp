#include <iostream>
#include <cmath>

int main() {
    double a, b, c;
    double discriminant, root1, root2;

    std::cout << "Enter coefficients a, b and c: ";
    std::cin >> a >> b >> c;

    discriminant = b*b - 4*a*c;

    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2*a);
        root2 = (-b - sqrt(discriminant)) / (2*a);
        std::cout << "The equation has two real roots: " << root1 << " and " << root2 << std::endl;
    } else if (discriminant == 0) {
        root1 = -b / (2*a);
        std::cout << "The equation has one real root: " << root1 << std::endl;
    } else {
        std::cout << "The equation has no real roots." << std::endl;
    }

    return 0;
}

