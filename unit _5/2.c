// Eular method

#include <stdio.h>

// Function f(x, y) = dy/dx
float f(float x, float y) {
    return x + y; // Example: dy/dx = x + y
}

int main() {
    float x0, y0, h, x_end, x, y;
    int n, i;

    // User inputs
    printf("Enter initial value of x (x0): ");
    scanf("%f", &x0);
    printf("Enter initial value of y (y0): ");
    scanf("%f", &y0);
    printf("Enter step size (h): ");
    scanf("%f", &h);
    printf("Enter final value of x (x_end): ");
    scanf("%f", &x_end);

    // Calculate number of steps
    n = (int)((x_end - x0) / h);

    // Initialize
    x = x0;
    y = y0;

    // Euler's Method
    printf("\nStep-by-step Results:\n");
    printf("x\t\t y\n");
    printf("%.4f\t %.4f\n", x, y);
    for (i = 0; i < n; i++) {
        y = y + h * f(x, y); // Update y using Euler's formula
        x = x + h;           // Increment x
        printf("%.4f\t %.4f\n", x, y);
    }

    return 0;
}
