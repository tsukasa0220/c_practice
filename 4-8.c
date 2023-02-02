#include <stdio.h>

int main(void) {
    int no;
    printf("³‚Ì®”:");
    scanf("%d",&no);

    while(no-->0){
        putchar('*');   
    } 
    if(no>=1){
        putchar('\n');
    }

    return 0;
}