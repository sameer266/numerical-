//    Gaussian Eliminatio

#include <stdio.h>

#define N 3  // Number of variables

// Function to perform Gaussian Elimination
void gaussianElimination(float a[N][N+1], float x[N]) {
    int i, j, k;
    float ratio;

    // Forward Elimination
    for (i = 0; i < N-1; i++) {
        // Make the pivot element 1 and eliminate the current variable from rows below
        for (j = i+1; j < N; j++) {
            if (a[j][i] != 0) {
                ratio = a[j][i] / a[i][i];
                for (k = i; k < N+1; k++) {
                    a[j][k] -= ratio * a[i][k];
                }
            }
        }
    }

    // Back Substitution
    x[N-1] = a[N-1][N] / a[N-1][N-1];  // Solve for the last variable

    for (i = N-2; i >= 0; i--) {
        x[i] = a[i][N];
        for (j = i+1; j < N; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];  // Solve for current variable
    }
}

int main() {
    float a[N][N+1] = {
        {2, -1, 1, 3},
        {-1, 2, 3, 3},
        {1, 3, 2, 5}
    };  // Augmented matrix of the system of equations
    float x[N];  // Array to store the solution

    // Perform Gaussian Elimination
    gaussianElimination(a, x);

    // Output the solution
    printf("Solution: \n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %.2f\n", i+1, x[i]);
    }

    return 0;
}
