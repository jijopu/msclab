#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

const double PI = 3.14159265358979323846;

// Define the function you want to analyze here
double func(double x) {
    return sin(2 * PI * x) + 0.5 * sin(4 * PI * x); // Example: f(x) = sin(2πx) + 0.5sin(4πx)
}

// Trapezoidal rule for numerical integration
double trapezoidalRule(function<double(double)> f, double a, double b, int n) {
    double h = (b - a) / n;
    double integral = (f(a) + f(b)) / 2;

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        integral += f(x);
    }

    integral *= h;
    return integral;
}

void fourierAnalysis(function<double(double)> f, double period, int numTerms) {
    double a0 = trapezoidalRule(f, 0, period, 1000) / period;
    cout << "a0: " << a0 << endl;

    for (int n = 1; n <= numTerms; n++) {
        auto fnCos = [&](double x) {
            return f(x) * cos(2 * PI * n * x / period);
        };
        auto fnSin = [&](double x) {
            return f(x) * sin(2 * PI * n * x / period);
        };

        double an = 2 * trapezoidalRule(fnCos, 0, period, 1000) / period;
        double bn = 2 * trapezoidalRule(fnSin, 0, period, 1000) / period;

        cout << "a" << n << ": " << an << ", b" << n << ": " << bn << endl;
    }
}

int main() {
    double period;
    int numTerms;

    cout << "Enter the period of the function: ";
    cin >> period;
    cout << "Enter the number of terms to compute: ";
    cin >> numTerms;

    fourierAnalysis(func, period, numTerms);

    return 0;
}
