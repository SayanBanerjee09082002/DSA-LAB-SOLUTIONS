#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

struct timeval t1, t2;
double time_taken;

// factorial of a number without tail recursion
long long int factNTR(long long int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factNTR(n - 1);
    }
}

// factorial of a number by implementing tail recursion
long long int factTR(long long int n, long long int acc)
{
    if (n == 0)
    {
        return acc;
    }
    else
    {
        return factTR(n - 1, n * acc);
    }
}

int main() {
    long long int factorial, num = 10;

    gettimeofday(&t1, NULL);
    factorial = factNTR(num);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("FACTORIAL OF 10 BY FACTORIAL WITHOUT TAIL RECURSION        = %lld\n", factorial);
    printf("TIME TAKEN FOR CALCULATING FACTORIAL WITHOUT TAIL RECURSION = %f seconds\n\n", time_taken);

    gettimeofday(&t1, NULL);
    factorial = factTR(num - 1, num);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("FACTORIAL OF 10 BY FACTORIAL WITH TAIL RECURSION        = %lld\n", factorial);
    printf("TIME TAKEN FOR CALCULATING FACTORIAL WITH TAIL RECURSION = %f seconds\n", time_taken);
    
    return 0;
}
