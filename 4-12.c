#include <stdio.h>

int main(void) {
    int no;
    int cnt=0;
    do{
        printf("���̐�������͂���:");
        scanf("%d",&no);
        if(no<=0){
            puts("���łȂ���������͂��Ȃ��ł��������B");
        }
    }while(no<=0);
    printf("%d��",no);
    while(no>0){
       no/=10;
       cnt++; 
    }
    printf("%d���ł��B\n",cnt);

    return 0;
}