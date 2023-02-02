#include <stdio.h>


int main(void)
{
    int ch;
    while ((ch = getchar()) != EOF) {
        if (ch >= '0' && ch <= '0' + 5) {
            ch += 4;
        }else if (ch >= '0' + 6 && ch <= '0' + 9) {
            ch -= 6;
        }
       
        putchar(ch);
    }
    return 0;
}