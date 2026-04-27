#include <stdio.h>

double divide(double dividend, double divisor)
{
    if (divisor == 0)
    {
        printf("invalid. Cannot divide by zero.\n");
        return 0;
    }

    double count = 0;
    double i = 0;

    while (i < dividend)
    {
        i += divisor;
        if (i < dividend)
        {
            count = count + 1;
        }
    }

    return count;
}

int main()
{
    double divi = 10000000, divs = 3, result;
    result = divide(divi, divs);
    printf("the result is : %.0f", result);
    return 0;
}