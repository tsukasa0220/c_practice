#include <stdio.h>

int main(void) {
	double no;
    printf("�����[�g������Ă��܂����H"); scanf("%lf",&no);

    if (no<1.0){
        puts("����Ȃɂ������Ȃ��ł��������B");
    }else if(no<2.5){
        puts("������������Ă��������B");
    }else if(no<4.0){
        puts("�����������������ق������S�ł��B");
    }else {
        puts("���S�ȋ����ł��B");
    }
    return 0;
}