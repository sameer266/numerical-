//  Romberg Integration:
#include <stdio.h>
#include <math.h>

// Define the function to be integrated
float f(float x) {
    return x * x; // Example: f(x) = x^2
}

// Romberg Integration function
float romberg_integration(float a, float b, int max_iter) {
    float R[max_iter][max_iter]; // Table to store results
    float h = b - a;
    int i, j;

    // Step 1: Initialize R(1, 1)
    R[0][0] = (h / 2) * (f(a) + f(b));

    // Step 2: Compute the values iteratively
    for (i = 1; i < max_iter; i++) {
        h /= 2; // Reduce step size by half each time
        float sum = 0;

        // Sum the interior points for the trapezoidal rule
        for (j = 1; j <= pow(2, i-1); j++) {
            sum += f(a + (2 * j - 1) * h);
        }

        // Apply the trapezoidal rule for R(i,1)
        R[i][0] = 0.5 * R[i-1][0] + sum * h;

        // Compute the higher-order estimates using the Romberg formula
        for (j = 1; j <= i; j++) {
            R[i][j] = (pow(4, j) * R[i][j-1] - R[i-1][j-1]) / (pow(4, j) - 1);
        }
    }

    // Return the final estimate of the integral
    return R[max_iter-1][max_iter-1];
}

int main() {
    float a, b, result;
    int max_iter;

    // Input values
    printf("Enter the lower limit (a): ");
    scanf("%f", &a);
    printf("Enter the upper limit (b): ");
    scanf("%f", &b);
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iter);

    // Call Romberg Integration function
    result = romberg_integration(a, b, max_iter);

    // Output the result
    printf("The approximate integral is: %.6f\n", result);

    return 0;
}
