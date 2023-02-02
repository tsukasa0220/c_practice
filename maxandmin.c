#include <stdio.h>

#define M 10
#define N 5

int main(void) 
{
	int grades[M][N] = { { 64, 89, 46, 98, 75 },
                         { 23, 13, 56, 33, 29 },
                         { 89, 92, 98, 88, 98 },
                         { 45, 42, 56, 60, 39 }, 
                         { 65, 62, 60, 70, 64 }, 
                         { 95, 94, 92, 90, 99 }, 
                         { 88, 74, 89, 80, 78 }, 
                         { 12,  1,  9, 18, 14 }, 
                         { 72, 84, 82, 77, 92 }, 
                         { 46, 39, 55, 80, 21 } };
    int max[N];
    int min[N];
    int i, j;

    for (i = 0; i < N; i++) {
        max[i] = grades[0][i];
        min[i] = grades[0][i];
        for (j = 1; j < M; j++) {
            if (grades[j][i] > max[i]) {
                max[i] = grades[j][i];
            }
            if (grades[j][i] < min[i]) {
                min[i] = grades[j][i];
            }

        }
    }

    for (i = 0; i < N; i++) {
        printf("第%2d回のテストの最高得点は%3d点、最低点は%3d点です。\n", i + 1, max[i], min[i]);
    }
    return 0;
}