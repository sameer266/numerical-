#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

// Function f(x, y, y') = y'' (dy/dx)
float f(float x, float y, float yp) {
    return -y; // Example: y'' = -y
}

// Solve the IVP using Euler's method
void solveIVP(float y0, float yp0, float h, int steps, float *y) {
    float x = 0;
    float y_current = y0;
    float yp_current = yp0;
    
    for (int i = 0; i < steps; i++) {
        // Euler's method for dy/dx and y''/dx
        y_current += h * yp_current;
        yp_current += h * f(x, y_current, yp_current);
        x += h;
    }
    
    *y = y_current;
}

int main() {
    float a = 0, b = M_PI, alpha = 1, beta = 0; // Boundary conditions: y(0) = 1, y(π) = 0
    float h = 0.1;  // Step size
    int steps = (int)((b - a) / h);  // Number of steps
    float y_guess = 0.0, yp_guess = 0.5;  // Initial guess for y'(a)
    float y_at_b;
    float tolerance = 0.01;  // Convergence tolerance
    int max_iter = 100;  // Maximum number of iterations for adjusting guess
    int iter;

    printf("Shooting Method for Boundary Value Problem\n");

    // Iterate to adjust the guess for y'(a)
    for (iter = 0; iter < max_iter; iter++) {
        // Solve the IVP with the current guess of y'(a)
        solveIVP(alpha, yp_guess, h, steps, &y_at_b);
        
        printf("Iteration %d: y(π) = %.5f, y'(0) = %.5f\n", iter + 1, y_at_b, yp_guess);
        
        // Check if the solution is within the tolerance
        if (fabs(y_at_b - beta) < tolerance) {
            printf("Converged to solution with y'(0) = %.5f\n", yp_guess);
            break;
        }
        
        // Adjust the guess for y'(a) based on the difference
        yp_guess = yp_guess + 0.1 * (beta - y_at_b);  // Adjust step size for the guess
    }

    if (iter == max_iter) {
        printf("Max iterations reached without convergence.\n");
    }

    return 0;
}
