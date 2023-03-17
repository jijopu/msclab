#include <iostream>
#include <vector>

using namespace std;

double lagrangeInterpolation(const vector<double>& x, const vector<double>& y, double xValue) {
    double result = 0;
    int n = x.size();

    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                term *= (xValue - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);

    cout << "Enter the x and y values for the data points:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    double xValue;
    cout << "Enter the x value for which you want to estimate the corresponding y value: ";
    cin >> xValue;

    double yValue = lagrangeInterpolation(x, y, xValue);
    cout << "The estimated y value using Lagrange interpolation is: " << yValue << endl;

    return 0;
}
