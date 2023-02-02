#include <stdio.h>

int data1[6] = {1, -2, 13, 6, 6, 8};       /* 3 ‚Ì”{”‚ÌÅ‘å’l‚Í 6 */
int data2[7] = {6,  2,  3,  6,  7, -1, 9}; /* 3 ‚Ì”{”‚ÌÅ‘å’l‚Í 9 */
int data3[3] = {1,  4,  5};                /* 3 ‚Ì”{”‚ª‘¶İ‚µ‚È‚¢ */ 
int data4[6] = {1,  1,  -10, 2, -6, -12};  /* 3 ‚Ì”{”‚ÌÅ‘å’l‚Í -6 */

int findMult3Max(const int v[], int no) 
{
    int x = -1;
    int max;
    int only = 0;
    for (int i = 0; i < no; i++) {
        if (v[i] % 3 == 0) {
            if (only == 0) {
                max = v[i];
                x = i;
                only++;
            }
            if (v[i] > max) {
                max = v[i];
                x = i;
            }
        }
    }
    return x;
}

int main(void) {
    printf("findMult3Max(data1, 6) = %d\n", findMult3Max(data1, 6));
    printf("findMult3Max(data2, 7) = %d\n", findMult3Max(data2, 7));
    printf("findMult3Max(data3, 3) = %d\n", findMult3Max(data3, 3));
    printf("findMult3Max(data4, 6) = %d\n", findMult3Max(data4, 6));

    return 0;
}