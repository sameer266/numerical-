// Power Method

#include <stdio.h>
#include <math.h>

#define N 3         // Dimension of the matrix
#define TOL 0.0001  // Convergence tolerance
#define MAX_ITER 100  // Maximum number of iterations

// Function to find the largest eigenvalue using the Power Method
void powerMethod(float A[N][N], float x[N], float *eigenvalue, float eigenvector[N]) {
    float y[N], norm, error, prev_eigenvalue;
    int i, j, k;

    // Normalize the initial vector x
    norm = 0;
    for (i = 0; i < N; i++) {
        norm += x[i] * x[i];
    }
    norm = sqrt(norm);
    for (i = 0; i < N; i++) {
        x[i] /= norm;
    }

    for (k = 0; k < MAX_ITER; k++) {
        // Multiply A with the current vector x to get y
        for (i = 0; i < N; i++) {
            y[i] = 0;
            for (j = 0; j < N; j++) {
                y[i] += A[i][j] * x[j];
            }
        }

        // Find the eigenvalue as the maximum absolute value in y
        prev_eigenvalue = *eigenvalue;
        *eigenvalue = fabs(y[0]);
        for (i = 1; i < N; i++) {
            if (fabs(y[i]) > *eigenvalue) {
                *eigenvalue = fabs(y[i]);
            }
        }

        // Normalize the vector y to get the next x
        norm = 0;
        for (i = 0; i < N; i++) {
            y[i] /= *eigenvalue;
            norm += y[i] * y[i];
        }
        norm = sqrt(norm);
        for (i = 0; i < N; i++) {
            x[i] = y[i] / norm;
        }

        // Check for convergence
        error = fabs(*eigenvalue - prev_eigenvalue);
        if (error < TOL) {
            break;
        }
    }

    // Store the final eigenvector
    for (i = 0; i < N; i++) {
        eigenvector[i] = x[i];
    }
}

int main() {
    float A[N][N] = {
        {4, 1, 1},
        {1, 3, 1},
        {1, 1, 2}
    };  // Input matrix
    float x[N] = {1, 1, 1};  // Initial guess for the eigenvector
    float eigenvalue = 0;    // Variable to store the largest eigenvalue
    float eigenvector[N];    // Array to store the eigenvector

    // Apply the Power Method
    powerMethod(A, x, &eigenvalue, eigenvector);

    // Output the results
    printf("Largest Eigenvalue: %.4f\n", eigenvalue);
    printf("Corresponding Eigenvector:\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %.4f\n", i + 1, eigenvector[i]);
    }

    return 0;
}
