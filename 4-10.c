#include <stdio.h>

int main(void) {
    int no;
    printf("���̐���:");
    scanf("%d",&no);

    while(no-->0){
        putchar('*');
        puts("");
    }
    return 0;
}