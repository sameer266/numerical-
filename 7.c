// Inverse Using Gaussian Elimination:
#include <stdio.h>

#define N 3  // Size of the matrix (3x3)

void gaussJordanInverse(float a[N][N], float inv[N][N]) {
    float temp;
    int i, j, k;

    // Create an augmented matrix [A | I]
    float augmented[N][2 * N];
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            augmented[i][j] = a[i][j]; // Copy A to the left side
            augmented[i][j + N] = (i == j) ? 1 : 0; // Identity matrix on the right side
        }
    }

    // Perform Gauss-Jordan Elimination
    for (i = 0; i < N; i++) {
        // Make the diagonal element 1
        temp = augmented[i][i];
        for (j = 0; j < 2 * N; j++) {
            augmented[i][j] /= temp;
        }

        // Eliminate the current column from all other rows
        for (j = 0; j < N; j++) {
            if (i != j) {
                temp = augmented[j][i];
                for (k = 0; k < 2 * N; k++) {
                    augmented[j][k] -= augmented[i][k] * temp;
                }
            }
        }
    }

    // The right side of the augmented matrix is now the inverse
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            inv[i][j] = augmented[i][j + N];
        }
    }
}

int main() {
    float a[N][N] = {
        {2, -1, 1},
        {-1, 2, 3},
        {1, 3, 2}
    };  // Input matrix
    float inv[N][N];  // Array to store the inverse

    // Find the inverse using Gauss-Jordan Elimination
    gaussJordanInverse(a, inv);

    // Output the inverse matrix
    printf("Inverse Matrix: \n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f ", inv[i][j]);
        }
        printf("\n");
    }

    return 0;
}
