#include <stdio.h>

int main(void) {

int x,y;	
printf("���ʂ̌�����͂��Ă�������:"); scanf("%d",&x);
printf("�ԋʂ̌�����͂��Ă�������:"); scanf("%d",&y);
printf("���ʂ̊�����%f%%�ł��B\n",(double)x/(x+y)*100);
    
    return 0;
}