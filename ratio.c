#include <stdio.h>

int main(void) {
	
	int x,y;
	
	printf("���ʂ̌�����͂��Ă�������:"); scanf("%d",&x);
	printf("�ԋʂ̌�����͂��Ă�������:"); scanf("%d",&y);
	
    printf("���ʂ̊�����%d%%�ł��B\n",100*x/(x+y));

    return 0;
}