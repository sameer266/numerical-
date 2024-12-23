//  Picard’s Method

#include <stdio.h>
#include <math.h>

// Function f(x, y) = dy/dx
float f(float x, float y) {
    return x + y; // Example: dy/dx = x + y
}

int main() {
    float x0, y0, h, x_end, x, y, y_new;
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

    // Calculate the number of steps
    n = (int)((x_end - x0) / h);

    // Initialize
    x = x0;
    y = y0;

    // Picard's Iteration
    printf("\nStep-by-step Results:\n");
    printf("x\t\t y\n");
    printf("%.4f\t %.4f\n", x, y);

    for (i = 0; i < n; i++) {
        // Approximate the next value of y using Picard's method
        y_new = y + h * f(x, y);
        x = x + h;
        
        // Update y and print the result
        y = y_new;
        printf("%.4f\t %.4f\n", x, y);
    }

    return 0;
}
