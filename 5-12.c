#include <stdio.h>

#define NUMBER 4
int main(void) 
{
    int tensu[NUMBER][4][3] = { { {91, 63, 78}, {67, 72, 46}, {89, 34, 53}, {32, 54, 34} },
                                { {97, 67, 82}, {73, 43, 46}, {97, 56, 21}, {85, 46, 35} },
                                { {34, 76, 70}, {99, 65, 42}, {79, 61, 44}, {39, 62, 28} },
                                { {75, 81, 68}, {87, 57, 40}, {73, 70, 42}, {81, 67, 72} } };
    int sum[4][3] = {0};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < NUMBER; k++) {
                sum[i][j] += tensu[k][i][j];
            }
        }
    }

    for (int i = 0; i < NUMBER; i++) {
        printf("%d‰ñ–Ú‚Ì“_”\n", i + 1);
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 3; k++) {
                printf("%4d", tensu[i][j][k]);
            }
            putchar('\n');
        }
    }

    puts("‡Œv“_");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%4d", sum[i][j]);
        }
        putchar('\n');
    }

    return 0;
}