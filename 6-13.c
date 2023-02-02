#include <stdio.h>

void mat_set(const int a[4][3], const int b[4][3], int c[2][4][3])
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            c[0][i][j] = a[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            c[1][i][j] = b[i][j];
        }
    }
}

void mat_print(const int a[2][4][3])
{
    for (int i = 0; i < 2; i++) {
        printf("%d‰ñ–Ú‚Ì“_”\n", i + 1);
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 3; k++) {
                printf("%4d", a[i][j][k]);
            }
            putchar('\n');
        }
    }
    puts("‡Œv“_");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%4d", a[0][i][j] + a[1][i][j]);
        }
        putchar('\n');
    }
}

int main(void)
{
    int tensu1[4][3] = { {91, 63, 78}, {67, 72, 46}, {89, 34, 53}, {32, 54, 34} };
    int tensu2[4][3] = { {97, 67, 82}, {73, 43, 46}, {97, 56, 21}, {85, 46, 35} };
    int tensu[2][4][3];

    mat_set(tensu1, tensu2, tensu);
    mat_print(tensu);


    return 0;
}