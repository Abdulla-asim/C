#include <stdio.h>

int main() 
{
    double s = 0.0, vi, v;
    const double dt = 0.01;
    const double g = 9.8;

    do
    {
        printf("Initial Velocity (50-150 m/s): ");
        scanf("%lf", &vi);
    }
    while (vi < 50 || vi > 150);

    v = vi;

    while (s >= 0)
    {
        int t;
        for (t = 0; t < 100; t++)
        {
            v = v - g * dt;
            s = s + v * dt;
        }
        double exact_position = vi * (t / 100.0) - 0.5 * g * (t / 100.0) * (t / 100.0);
        printf("Time: %.2f s - Approximate Position: %.2f m - Exact Position: %.2f m\n", t / 100.0, s, exact_position);
    }

    printf("The cannonball has fallen back to the ground.\n");

    return 0;
}
