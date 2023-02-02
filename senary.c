#include <stdio.h>

void printSenary(int n)
{
    if (n >= 6) {
        printSenary(n / 6);
    }
    printf("%d", n % 6);
}


int main(void)
{
    int no;
    printf("整数を入力してください：");
    do {
        scanf("%d", &no);
        if (no < 0) {
            printf("非負の整数を入力してください：");
        }
    }while (no < 0);
    printf("その数の6進数による表現は");
    printSenary(no);
    printf("です。\n");

    return 0;
}