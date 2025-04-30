#include <stdarg.h>
#include <stdio.h>


double max(int count, ...)
{
    va_list args;
    va_start(args, count);
    double max_val = 0;
    for (int i = 0; i < count; i++)
    {
        double val = va_arg(args, double);
        if (val > max_val)
        {
            max_val = val;
        }
    }
    va_end(args);
    return max_val;
}

int main()
{
    double max_value = max(5, 1.0, 2.5, 3.8, 4.2, 5.6);
    printf("Le plus grand nombre est : %f\n", max_value);
    return 0;
}
