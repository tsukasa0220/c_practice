#include <stdio.h>

#define NUMBER 120

int main(void) 
{
    int num;
    int tensu[NUMBER];
    int bunpu[11] = {0};

    printf("人数を入力せよ：");
    do {
        scanf("%d", &num);
        if (num < 1 || num > NUMBER) {
            printf("1~120で入力せよ：");
        }
    } while (num < 1 || num > NUMBER);

    printf("%d人の点数を入力せよ。\n", num);
    
    for (int i = 0; i < num; i++) {
        printf("%2d番：", i + 1);
        do {
            scanf("%d", &tensu[i]);
            if (tensu[i] < 0 || tensu[i] > 100) {
                printf("0~100で入力せよ：");
            }
        } while (tensu[i] < 0 || tensu[i] > 100);
        bunpu[tensu[i] / 10]++;
    }

    int max_bunpu = bunpu[0];
    for (int i = 1; i <= 10; i++) {
        if (bunpu[i] > max_bunpu) {
            max_bunpu = bunpu[i];
        }
    }

    puts("\n------------分布グラフ------------");
    for (int i = max_bunpu; i >= 1; i--) {
        for (int j = 0; j <= 10; j++) {
            if (bunpu[j] >= i) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        putchar('\n');
    }

    puts("----------------------------------");
    puts(" 0 10 20 30 40 50 60 70 80 90 100 ");

    return 0;
}