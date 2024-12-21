// Simpson’s 3/8 Rule:
#include <stdio.h>
#include <math.h>

// Define the function to be integrated
float f(float x) {
    return x * x; // Example: f(x) = x^2
}

// Simpson's 3/8 rule function
float simpsons_38_rule(float a, float b, int n) {
    if (n % 3 != 0) {
        printf("Error: Number of subintervals (n) must be a multiple of 3.\n");
        return -1;
    }

    float h, sum, x;
    int i;

    h = (b - a) / n;  // Step size
    sum = f(a) + f(b); // Add the first and last terms

    // Loop over the interior points
    for (i = 1; i < n; i++) {
        x = a + i * h;
        if (i % 3 == 0) {
            sum += 2 * f(x); // Every third index
        } else {
            sum += 3 * f(x); // Other interior points
        }
    }

    return sum * 3 * h / 8.0; // Final result
}

int main() {
    float a, b, result;
    int n;

    // Input values
    printf("Enter the lower limit (a): ");
    scanf("%f", &a);
    printf("Enter the upper limit (b): ");
    scanf("%f", &b);
    printf("Enter the number of subintervals (n, multiple of 3): ");
    scanf("%d", &n);

    // Call Simpson's 3/8 rule function
    result = simpsons_38_rule(a, b, n);

    if (result != -1) {
        // Output the result
        printf("The approximate integral is: %.4f\n", result);
    }

    return 0;
}
