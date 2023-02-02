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

    int max_bunpu = bunpu[0];
    for (int i = 1; i <= 10; i++) {
        if (bunpu[i] > max_bunpu) {
            max_bunpu = bunpu[i];
        }
    }

    puts("\n------------���z�O���t------------");
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