#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

struct timeval t1, t2;
double time_taken;

long long int recursive_fibonacci_generator(long long int nums) {
    if (nums == 0)
        return 0LL;
    else if (nums == 1)
        return 1LL;     
    else
        return recursive_fibonacci_generator(nums - 2) + recursive_fibonacci_generator(nums - 1);
}

long long int iterative_fibonacci_generator(long long int nums) {
    long long int result = 0LL, num1 = 0LL, num2 = 1LL;

    if (nums == 1)
        return 0LL;
    else if (nums == 2)
        return 1LL;     
    else {
        for (long long int i = 2LL; i <= nums; i++) {
            result = num1 + num2;
            num1 = num2;
            num2 = result;
        }
        return result;
    }
}

int main() {
    long long int result;

    gettimeofday(&t1, NULL);
    result = recursive_fibonacci_generator(30);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("TIME FOR 30TH FIBONACCI NUMBER BY RECURSION     = %lld\n", result);
    printf("TIME TAKEN TO GENERATE RESULT BY RECURSION      = %f\n\n", time_taken);

    gettimeofday(&t1, NULL);
    result = iterative_fibonacci_generator(30);
    gettimeofday(&t2, NULL);
    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("TIME FOR 30TH FIBONACCI NUMBER BY ITERATION     = %lld\n", result);
    printf("TIME TAKEN TO GENERATE RESULT BY ITERATION      = %f\n", time_taken);
}