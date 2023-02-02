#include <stdio.h>

int scan(void) 
{
    int tmp;
    do {
        scanf("%d", &tmp);
        if (tmp < 0) {
            printf("非負の整数で入力してください：");
        }
    }while (tmp < 0);
    return tmp;
}

void kyoto(int x1, int y1, int x2, int y2) 
{
    if (x1 >= x2 && y1 >= y2) {
        putchar('\n');
        return;
    }
    if (x1 < x2) {
        printf("E");
        kyoto(x1 + 1, y1, x2, y2);
    }
    if (y1 < y2) {
        printf("S");
        kyoto(x1, y1 + 1, x2, y2);
    }
    
}

int main(void)
{
    
    puts("A地点とB地点を入力してください。");
    printf("A地点,X：");
    int x1 = scan();
    printf("A地点,Y：");
    int y1 = scan();
    printf("B地点,X：");
    int x2 = scan();
    printf("B地点,Y：");
    int y2 = scan();

    kyoto(x1, y1, x2, y2);
    
    return 0;
}