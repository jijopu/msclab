#include <iostream>

const int MAX_SIZE = 10;

// Function to input a matrix
void inputMatrix(double matrix[][MAX_SIZE], int n) {
    std::cout << "Enter matrix elements:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(double matrix[][MAX_SIZE], int n) {
    std::cout << "Matrix:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

// Function to find the inverse of a matrix
bool inverseMatrix(double matrix[][MAX_SIZE], int n, double inverse[][MAX_SIZE]) {
    double temp[MAX_SIZE][MAX_SIZE];
    double ratio, det = 1.0;

    // Initialize the inverse matrix to the identity matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                inverse[i][j] = 1.0;
            } else {
                inverse[i][j] = 0.0;
            }
            temp[i][j] = matrix[i][j];
        }
    }

    // Apply Gauss-Jordan elimination to find the inverse
    for (int i = 0; i < n; ++i) {
        // Check if the diagonal element is zero
        if (temp[i][i] == 0.0) {
            return false;
        }

        // Divide the row by the diagonal element to make it 1
        ratio = temp[i][i];
        det *= ratio;
        for (int j = 0; j < n; ++j) {
            temp[i][j] /= ratio;
            inverse[i][j] /= ratio;
        }

        // Subtract the row from all other rows to make the other elements 0
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                ratio = temp[j][i];
                for (int k = 0; k < n; ++k) {
                    temp[j][k] -= ratio * temp[i][k];
                    inverse[j][k] -= ratio * inverse[i][k];
                }
            }
        }
    }

    return true;
}

int main() {
    int n;
    double matrix[MAX_SIZE][MAX_SIZE], inverse[MAX_SIZE][MAX_SIZE];

    // Input matrix
    std::cout << "Enter the number of rows and columns of the matrix: ";
    std::cin >> n;
    inputMatrix(matrix, n);

    // Find the inverse of the matrix
    if (inverseMatrix(matrix, n, inverse)) {
        std::cout << "Inverse of the matrix:" << std::endl;
        printMatrix(inverse, n);
    } else {
        std::cout << "Matrix is singular, inverse does not exist." << std::endl;
    }

    return 0;
}
