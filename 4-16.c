#include <stdio.h>
int main(void) {
    int no;
    printf("®”’l:");
    scanf("%d",&no);
    for(int i=1;i<=no;i+=2){
        printf("%d ",i);
    }
    putchar('\n');
    return 0;
}