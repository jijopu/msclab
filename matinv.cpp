#include <iostream>
#include <vector>

using namespace std;

bool findInverse(vector<vector<double>>& matrix, vector<vector<double>>& inverse) {
    int n = matrix.size();

    // Initialize the inverse matrix with the identity matrix.
    for (int i = 0; i < n; i++) {
        inverse[i][i] = 1;
    }

    // Perform Gauss-Jordan elimination on the matrix.
    for (int i = 0; i < n; i++) {
        // Find the pivot element in the current column.
        double maxVal = abs(matrix[i][i]);
        int pivotRow = i;
        for (int row = i + 1; row < n; row++) {
            if (abs(matrix[row][i]) > maxVal) {
                maxVal = abs(matrix[row][i]);
                pivotRow = row;
            }
        }

        if (maxVal == 0) {
            return false; // Singular matrix, no inverse exists.
        }

        // Swap the current row with the pivot row.
        if (pivotRow != i) {
            swap(matrix[i], matrix[pivotRow]);
            swap(inverse[i], inverse[pivotRow]);
        }

        // Normalize the current row.
        double scaleFactor = matrix[i][i];
        for (int j = 0; j < n; j++) {
            matrix[i][j] /= scaleFactor;
            inverse[i][j] /= scaleFactor;
        }

        // Eliminate other rows using the current row.
        for (int row = 0; row < n; row++) {
            if (row == i) continue;
            double factor = matrix[row][i];
            for (int col = 0; col < n; col++) {
                matrix[row][col] -= factor * matrix[i][col];
                inverse[row][col] -= factor * inverse[i][col];
            }
        }
    }

    return true;
}

int main() {
    int n;
    cout << "Enter the dimension of the matrix: ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n));
    vector<vector<double>> inverse(n, vector<double>(n));

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    if (findInverse(matrix, inverse)) {
        cout << "The inverse of the matrix is:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << inverse[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "The matrix is singular, no inverse exists." << endl;
    }

    return 0;
}
