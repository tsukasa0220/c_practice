#include <stdio.h>
int main(void) {
    int no;
    printf("����n��\�����܂���:");
    scanf("%d",&no);
    for(int i=1;i<=no;i++){
        putchar('*');
        if(i%5==0){
            putchar('\n');
        }
    }
    putchar('\n');
    return 0;
}