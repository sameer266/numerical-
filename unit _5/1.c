// Taylor method


#include <stdio.h>

// Define the function f(x, y) = dy/dx
float f(float x, float y) {
    return x + y; // Example: dy/dx = x + y
}

// Define the derivative of f(x, y) (if needed)
float f_prime(float x, float y) {
    return 1 + f(x, y); // Example: d²y/dx² = 1 + f(x, y)
}

int main() {
    float x0, y0, h, x_end;
    int n;

    // User input for initial values and step size
    printf("Enter initial x (x0): ");
    scanf("%f", &x0);
    printf("Enter initial y (y0): ");
    scanf("%f", &y0);
    printf("Enter step size (h): ");
    scanf("%f", &h);
    printf("Enter final x (x_end): ");
    scanf("%f", &x_end);

    // Calculate the number of steps
    n = (int)((x_end - x0) / h);

    // Taylor Method Loop
    printf("\nStep-by-step Results:\n");
    printf("x\t\t y\n");
    printf("%.4f\t %.4f\n", x0, y0);
    for (int i = 0; i < n; i++) {
        // Compute Taylor expansion terms
        float f_val = f(x0, y0);
        float f_prime_val = f_prime(x0, y0);

        // Update y using Taylor series up to the second-order term
        float y_next = y0 + h * f_val + (h * h / 2) * f_prime_val;

        // Update x and y for the next step
        x0 += h;
        y0 = y_next;

        // Print the current step
        printf("%.4f\t %.4f\n", x0, y0);
    }

    return 0;
}
