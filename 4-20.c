#include <stdio.h>
int main(void) {
    puts(" |  1  2  3  4  5  6  7  8  9 ");
    puts("------------------------------");
    for(int tate=1;tate<=9;tate++){
        printf("%d| ",tate);
        for(int yoko=1;yoko<=9;yoko++){
            printf("%2d ",tate*yoko);
        }
        putchar('\n');
    }
    return 0;
}