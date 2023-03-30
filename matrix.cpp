#include <iostream>

const int MAX_SIZE = 10;

// Function to input a matrix
void inputMatrix(int matrix[][MAX_SIZE], int rows, int columns) {
    std::cout << "Enter matrix elements:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[][MAX_SIZE], int rows, int columns) {
    std::cout << "Matrix:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

// Function to calculate the sum of two matrices
void sumMatrix(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int rows, int columns) {
    int result[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printMatrix(result, rows, columns);
}

// Function to calculate the product of two matrices
void productMatrix(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int rows1, int columns1, int rows2, int columns2) {
    int result[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < columns2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < columns1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    printMatrix(result, rows1, columns2);
}

// Function to calculate the transpose of a matrix
void transposeMatrix(int matrix[][MAX_SIZE], int rows, int columns) {
    int result[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < columns; ++i) {
        for (int j = 0; j < rows; ++j) {
            result[i][j] = matrix[j][i];
        }
    }
    printMatrix(result, columns, rows);
}

// Function to calculate the trace of a matrix
void traceMatrix(int matrix[][MAX_SIZE], int rows, int columns) {
    int trace = 0;
    for (int i = 0; i < rows; ++i) {
        trace += matrix[i][i];
    }
    std::cout << "Trace: " << trace << std::endl;
}

int main() {
    int rows, columns;
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE];

    // Input matrix 1
    std::cout << "Enter the number of rows and columns of matrix 1: ";
    std::cin >> rows >> columns;
    inputMatrix(matrix1, rows, columns);

    // Input matrix 2
    std::cout << "Enter the number of rows and columns of matrix 2: ";
    std::cin >> rows
