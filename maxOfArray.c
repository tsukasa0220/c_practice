#include <stdio.h>
#include <limits.h>

int maxOfArray(const int vc[])
{
    int i = 0;
    int max = INT_MIN;

    while (vc[i] != INT_MIN) {
        if (vc[i] > max) {
            max = vc[i];
        }
        i++;
    }
    return max;
}

int main(void)
{
    int test1[] = {10, 11, 12, 7, -16, -15, 6, INT_MIN};
    int test2[] = {8, 14, 14, -8, 9, 5, 24, -4, INT_MIN};
    int test3[] = {INT_MIN};
    int test4[] = {-19, INT_MIN};  

    printf("maxOfArray(test1)‚Í%d\n", maxOfArray(test1));
    printf("maxOfArray(test1)‚Í%d\n", maxOfArray(test2));
    printf("maxOfArray(test1)‚Í%d\n", maxOfArray(test3));
    printf("maxOfArray(test1)‚Í%d\n", maxOfArray(test4));

    
    return 0;
}
