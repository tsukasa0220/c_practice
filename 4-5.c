#include <stdio.h>

int main(void) {
    int no;
    printf("���̐�������͂���:"); scanf("%d",&no);
    int i=1;
    while(i<=no){
        printf("%d",i++);
    }
    if(no>0){
        printf("\n");
    }
   
    return 0;
}