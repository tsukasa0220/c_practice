#include <stdio.h>

int main(void) {
	int no;
    printf("��������͂��Ă�������:"); scanf("%d",&no);

    if (no<0){
        puts("���̒l�����͂���܂����B");
    }else if (no%5==0){
        puts("���̐���5�Ŋ���؂�܂��B");
    }else {
        printf("���̐���5�Ŋ������]���%d�ł��B\n",no%5);
    }

    return 0;
}