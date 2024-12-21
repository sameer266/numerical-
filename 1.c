// Trapezoidal Rule

#include <stdio.h>
#include <math.h>

// Define the function to be integrated
float f(float x) {
    return x * x; // Example: f(x) = x^2
}

// Trapezoidal rule function
float trapezoidal_rule(float a, float b, int n) {
    float h, sum, x;
    int i;
    
    h = (b - a) / n;  // Step size
    sum = (f(a) + f(b)) / 2.0; // Sum the first and last terms

    // Loop to calculate the sum of interior points
    for (i = 1; i < n; i++) {
        x = a + i * h;
        sum += f(x);  // Add f(x) for each interior point
    }

    return sum * h; // Final result
}

int main() {
    float a, b, result;
    int n;

    // Input values
    printf("Enter the lower limit (a): ");
    scanf("%f", &a);
    printf("Enter the upper limit (b): ");
    scanf("%f", &b);
    printf("Enter the number of subintervals (n): ");
    scanf("%d", &n);

    // Call the trapezoidal rule function
    result = trapezoidal_rule(a, b, n);

    // Output the result
    printf("The approximate integral is: %.4f\n", result);

    return 0;
}
