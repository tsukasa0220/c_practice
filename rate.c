#include <stdio.h>

int main(void) {
    int cnt1=0;
    int cnt=-1;
    int no;
    do{
        printf("��������͂��Ă��������i���̐��œ��͏I���j:"); 
        scanf("%d",&no);
        if(no>=50){
            cnt1++;
        }
        cnt++;
    }while(no>=0);

    printf("50�ȏ�̐��̊�����%f%%�ł�\n",(double)cnt1/cnt*100);
    return 0;
}