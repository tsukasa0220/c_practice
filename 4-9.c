#include <stdio.h>

int main(void) {
    int no;
    int i=0;
    printf("���̐���:");
    scanf("%d",&no);

    while(i++<no){
        putchar(i%2?'+':'-');
    }
    puts("");
    
    return 0;
}