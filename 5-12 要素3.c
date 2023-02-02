#include <stdio.h>

#define NUMBER 3

int main(void) 
{
    int tensu[NUMBER][4][3] =  { { {91, 63, 78}, {67, 72, 46}, {89, 34, 53}, {32, 54, 34} },
                                 { {97, 67, 82}, {73, 43, 46}, {97, 56, 21}, {85, 46, 35} },
                                 { {34, 76, 70}, {99, 65, 42}, {79, 61, 44}, {39, 62, 28} } };
    int sum[4][3] = {0};

    //合計の加算
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < NUMBER; k++) {
                sum[i][j] += tensu[k][i][j];
            }
        }
    }

　　//何回目の点数表示
    for (int i = 0; i < NUMBER; i++) {
        printf("%d回目の点数\n", i + 1);
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 3; k++) {
                printf("%4d", tensu[i][j][k]);
            }
            putchar('\n');
        }
    }

　　//合計点の表示
    puts("合計点");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%4d", sum[i][j]);
        }
        putchar('\n');
    }

    return 0;
}