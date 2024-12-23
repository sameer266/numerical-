// --Rk4   method
#include <stdio.h>

// Function f(x, y) = dy/dx
float f(float x, float y) {
    return x + y; // Example: dy/dx = x + y
}

int main() {
    float x0, y0, h, x_end, x, y, k1, k2, k3, k4;
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

    // RK4 Method
    printf("\nStep-by-step Results:\n");
    printf("x\t\t y\n");
    printf("%.4f\t %.4f\n", x, y);
    for (i = 0; i < n; i++) {
        // Calculate k1, k2, k3, k4
        k1 = h * f(x, y);
        k2 = h * f(x + h / 2, y + k1 / 2);
        k3 = h * f(x + h / 2, y + k2 / 2);
        k4 = h * f(x + h, y + k3);

        // Update y and x
        y = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        x = x + h;

        // Print the current step
        printf("%.4f\t %.4f\n", x, y);
    }

    return 0;
}
