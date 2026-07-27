// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================


#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, string label) {
    cout << "Enter matrix " << label << " (" << rows << " x " << cols << "):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transpose(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols,
               int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE],
                  int rows, int cols, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE],
                       int m, int n, int p, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            int total = 0;
            for (int k = 0; k < n; k++) {
                total += a[i][k] * b[k][j];
            }
            result[i][j] = total;
        }
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int matA[MAX_SIZE][MAX_SIZE], matB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    // ---------------- PART A: TRANSPOSE ----------------
    cout << "=== Part A: Transpose ===" << endl;
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    readMatrix(matrix, rows, cols, "");

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matrix, rows, cols);

    transpose(matrix, rows, cols, result);
    cout << "\nTransposed Matrix:" << endl;
    printMatrix(result, cols, rows);

    // ---------------- PART B: ADDITION ----------------
    cout << "\n=== Part B: Matrix Addition ===" << endl;
    cout << "Enter two matrices of size " << rows << " x " << cols << endl;
    readMatrix(matA, rows, cols, "A");
    readMatrix(matB, rows, cols, "B");

    int sumResult[MAX_SIZE][MAX_SIZE];
    addMatrices(matA, matB, rows, cols, sumResult);
    cout << "\nSum Matrix:" << endl;
    printMatrix(sumResult, rows, cols);

    // ---------------- PART C: MULTIPLICATION ----------------
    cout << "\n=== Part C: Matrix Multiplication ===" << endl;
    int m, n, p;
    cout << "Enter rows for Matrix A: ";
    cin >> m;
    cout << "Enter columns for Matrix A (= rows for Matrix B): ";
    cin >> n;
    cout << "Enter columns for Matrix B: ";
    cin >> p;

    int mulA[MAX_SIZE][MAX_SIZE], mulB[MAX_SIZE][MAX_SIZE];
    readMatrix(mulA, m, n, "A");
    readMatrix(mulB, n, p, "B");

    int product[MAX_SIZE][MAX_SIZE];
    multiplyMatrices(mulA, mulB, m, n, p, product);
    cout << "\nProduct Matrix (A x B):" << endl;
    printMatrix(product, m, p);

    return 0;
}
EOF

