#include <stdio.h>

#define NUMBER 3

int main(void) 
{
    int tensu[NUMBER][4][3] =  { { {91, 63, 78}, {67, 72, 46}, {89, 34, 53}, {32, 54, 34} },
                                 { {97, 67, 82}, {73, 43, 46}, {97, 56, 21}, {85, 46, 35} },
                                 { {34, 76, 70}, {99, 65, 42}, {79, 61, 44}, {39, 62, 28} } };
    int sum[4][3] = {0};

    //���v�̉��Z
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < NUMBER; k++) {
                sum[i][j] += tensu[k][i][j];
            }
        }
    }

�@�@//����ڂ̓_���\��
    for (int i = 0; i < NUMBER; i++) {
        printf("%d��ڂ̓_��\n", i + 1);
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 3; k++) {
                printf("%4d", tensu[i][j][k]);
            }
            putchar('\n');
        }
    }

�@�@//���v�_�̕\��
    puts("���v�_");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%4d", sum[i][j]);
        }
        putchar('\n');
    }

    return 0;
}