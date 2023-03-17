#include <iostream>
#include <vector>

using namespace std;

vector<double> gaussElimination(vector<vector<double>>& augmentedMatrix) {
    int n = augmentedMatrix.size();

    for (int i = 0; i < n; i++) {
        // Find the pivot element for the current row.
        int pivotRow = i;
        for (int row = i + 1; row < n; row++) {
            if (abs(augmentedMatrix[row][i]) > abs(augmentedMatrix[pivotRow][i])) {
                pivotRow = row;
            }
        }

        // Swap the current row with the pivot row.
        swap(augmentedMatrix[i], augmentedMatrix[pivotRow]);

        // Normalize the current row.
        double pivot = augmentedMatrix[i][i];
        for (int col = i; col <= n; col++) {
            augmentedMatrix[i][col] /= pivot;
        }

        // Eliminate other rows using the current row.
        for (int row = 0; row < n; row++) {
            if (row == i) continue;
            double factor = augmentedMatrix[row][i];
            for (int col = i; col <= n; col++) {
                augmentedMatrix[row][col] -= factor * augmentedMatrix[i][col];
            }
        }
    }

    vector<double> solution(n);
    for (int i = 0; i < n; i++) {
        solution[i] = augmentedMatrix[i][n];
    }

    return solution;
}

int main() {
    int n;
    cout << "Enter the number of linear equations: ";
    cin >> n;

    vector<vector<double>> augmentedMatrix(n, vector<double>(n + 1));

    cout << "Enter the coefficients of the linear equations and the constant terms:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> augmentedMatrix[i][j];
        }
    }

    vector<double> solution = gaussElimination(augmentedMatrix);

    cout << "The solution of the linear equations is:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }

    return 0;
}
