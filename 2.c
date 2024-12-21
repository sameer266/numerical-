// Simpson’s 1/3 Rule

#include <stdio.h>
#include <math.h>

float f(float x) {
    return x * x; // Example: f(x) = x^2
}

// Simpson's 1/3 rule function
float simpsons_rule(float a, float b, int n) {
    if (n % 2 != 0) {
        printf("Error: Number of subintervals (n) must be even.\n");
        return -1;
    }

    float h, sum, x;
    int i;

    h = (b - a) / n;  // Step size
    sum = f(a) + f(b); // Add the first and last terms

    // Loop over the interior points
    for (i = 1; i < n; i++) {
        x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * f(x); // Even index terms
        } else {
            sum += 4 * f(x); // Odd index terms
        }
    }

    return sum * h / 3.0; // Final result
}

int main() {
    float a, b, result;
    int n;

    // Input values
    printf("Enter the lower limit (a): ");
    scanf("%f", &a);
    printf("Enter the upper limit (b): ");
    scanf("%f", &b);
    printf("Enter the number of subintervals (n, even number): ");
    scanf("%d", &n);

    // Call Simpson's 1/3 rule function
    result = simpsons_rule(a, b, n);

    if (result != -1) {
        // Output the result
        printf("The approximate integral is: %.4f\n", result);
    }

    return 0;
}
