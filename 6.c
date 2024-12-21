//   Gauss-Jordan Elimination:

#include <stdio.h>

#define N 3  // Number of variables

// Function to perform Gauss-Jordan Elimination
void gaussJordanElimination(float a[N][N+1], float x[N]) {
    int i, j, k;
    float ratio;

    // Forward Elimination to make diagonal elements 1 and eliminate the column entries
    for (i = 0; i < N; i++) {
        // Make the pivot element 1
        float pivot = a[i][i];
        for (j = 0; j < N+1; j++) {
            a[i][j] /= pivot;
        }

        // Eliminate the current column from other rows
        for (j = 0; j < N; j++) {
            if (i != j) {
                ratio = a[j][i];
                for (k = 0; k < N+1; k++) {
                    a[j][k] -= ratio * a[i][k];
                }
            }
        }
    }

    // The solution is now in the last column of the augmented matrix
    for (i = 0; i < N; i++) {
        x[i] = a[i][N];  // Extract the solution
    }
}

int main() {
    float a[N][N+1] = {
        {2, -1, 1, 3},
        {-1, 2, 3, 3},
        {1, 3, 2, 5}
    };  // Augmented matrix of the system of equations
    float x[N];  // Array to store the solution

    // Perform Gauss-Jordan Elimination
    gaussJordanElimination(a, x);

    // Output the solution
    printf("Solution: \n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %.2f\n", i+1, x[i]);
    }

    return 0;
}
