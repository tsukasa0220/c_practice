#include <stdio.h>

#define NUMBER 120

int main(void) 
{
    int num;
    int tensu[NUMBER];
    int bunpu[11] = {0};

    printf("�l������͂���F");
    do {
        scanf("%d", &num);
        if (num < 1 || num > NUMBER) {
            printf("1~120�œ��͂���F");
        }
    } while (num < 1 || num > NUMBER);

    printf("%d�l�̓_������͂���B\n", num);
    
    for (int i = 0; i < num; i++) {
        printf("%2d�ԁF", i + 1);
        do {
            scanf("%d", &tensu[i]);
            if (tensu[i] < 0 || tensu[i] > 100) {
                printf("0~100�œ��͂���F");
            }
        } while (tensu[i] < 0 || tensu[i] > 100);
         bunpu[tensu[i] / 10]++;
    }

    puts("\n---���z�O���t---");
    for (int i = 0; i <= 9; i++) {
        printf("%3d �`%3d�F", i * 10, i * 10 + 9);
        for(int j = 0; j < bunpu[i]; j++) {
            putchar('*');
        }
        putchar('\n');
    }

    printf("      100�F");
    for (int j = 0; j < bunpu[10]; j++) {
        putchar('*');
    }
    putchar('\n');

    return 0;
}