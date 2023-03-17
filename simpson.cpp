#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

// Define the function you want to integrate here
double func(double x) {
    return x * x * x; // Example: f(x) = x^3
}

double simpsonsOneThirdRule(function<double(double)> f, double a, double b, int n) {
    double h = (b - a) / n;

    double result = f(a) + f(b);

    for (int i = 1; i <= n - 1; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            result += 2 * f(x);
        } else {
            result += 4 * f(x);
        }
    }

    result *= (h / 3);
    return result;
}

int main() {
    double a, b;
    int n;

    cout << "Enter the lower limit of integration (a): ";
    cin >> a;
    cout << "Enter the upper limit of integration (b): ";
    cin >> b;
    cout << "Enter the number of intervals (n, must be even): ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Error: The number of intervals must be even." << endl;
        return 1;
    }

    double result = simpsonsOneThirdRule(func, a, b, n);
    cout << "The integral of the function using Simpson's 1/3 Rule is: " << result << endl;

    return 0;
}
