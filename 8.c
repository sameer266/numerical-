//   Gacobi and Gauss-Seidel#include <stdio.h>
#include <math.h>

#define N 3  // Number of equations
#define TOL 0.0001  // Convergence tolerance
#define MAX_ITER 100  // Maximum iterations

void jacobi(float a[N][N], float b[N], float x[N]) {
    float x_new[N], sum;
    int i, j, k;

    for (k = 0; k < MAX_ITER; k++) {
        for (i = 0; i < N; i++) {
            sum = b[i];
            for (j = 0; j < N; j++) {
                if (i != j) {
                    sum -= a[i][j] * x[j];
                }
            }
            x_new[i] = sum / a[i][i];
        }

        // Check for convergence
        int converged = 1;
        for (i = 0; i < N; i++) {
            if (fabs(x_new[i] - x[i]) > TOL) {
                converged = 0;
                break;
            }
        }
        if (converged) break;

        // Update x
        for (i = 0; i < N; i++) {
            x[i] = x_new[i];
        }
    }
}

void gaussSeidel(float a[N][N], float b[N], float x[N]) {
    float sum;
    int i, j, k;

    for (k = 0; k < MAX_ITER; k++) {
        int converged = 1;
        for (i = 0; i < N; i++) {
            sum = b[i];
            for (j = 0; j < N; j++) {
                if (i != j) {
                    sum -= a[i][j] * x[j];
                }
            }
            float x_new = sum / a[i][i];

            // Check for convergence
            if (fabs(x_new - x[i]) > TOL) {
                converged = 0;
            }

            // Update x immediately (Gauss-Seidel specific)
            x[i] = x_new;
        }

        if (converged) break;
    }
}

int main() {
    float a[N][N] = {
        {4, -1, 0},
        {-1, 4, -1},
        {0, -1, 4}
    };  // Coefficient matrix
    float b[N] = {15, 10, 10};  // Constant terms
    float x[N] = {0, 0, 0};  // Initial guess

    printf("Jacobi Method:\n");
    jacobi(a, b, x);
    for (int i = 0; i < N; i++) {
        printf("x%d = %.4f\n", i + 1, x[i]);
    }

    // Reset initial guess for Gauss-Seidel
    for (int i = 0; i < N; i++) {
        x[i] = 0;
    }

    printf("\nGauss-Seidel Method:\n");
    gaussSeidel(a, b, x);
    for (int i = 0; i < N; i++) {
        printf("x%d = %.4f\n", i + 1, x[i]);
    }

    return 0;
}
