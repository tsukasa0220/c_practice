#include <stdio.h>

int main(void) {
    int no1,no2;
    puts("��̂O�܂��͐��̐�������͂��Ă��������B");
    printf("�����P:"); scanf("%d",&no1);
    printf("�����Q:"); scanf("%d",&no2);

    if(no1%2==0&&no2%2==0){
        puts("�����̐��������ł��B");
    }else{
        puts("���Ȃ��Ƃ�����̐��������ł͂���܂���B");
    }
    
    return 0;
}