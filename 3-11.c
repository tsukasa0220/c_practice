#include <stdio.h>

int main(void) {
	
int a,b;
puts("��̐�������͂���B");
printf("����A:"); scanf("%d",&a);
printf("����B:"); scanf("%d",&b);

if (a-b>10||b-a>10){
    puts("�����̍���11�ȏ�ł��B");
}else {
    puts("�����̍���10�ȉ��ł��B");
}
    
    return 0;
}