#include <stdio.h>

int main(void) {

int retry;

do{
    int no;
    printf("��������͂���F"); scanf("%d",&no);
    if(no==0){
        puts("���̐���0�ł��B");
    }else if(no>0){
        puts("���̐��͐��ł��B");
    }else{
        puts("���̐��͕��ł��B");
    }
    printf("�����܂����H�yYes���0/No���9�z"); scanf("%d",&retry);
}while (retry==0);

    return 0;
}