#include <stdio.h>

int main(void) {
    int a,b;

    puts("��̐�������͂���B");
    printf("����a�F"); scanf("%d",&a);
	printf("����b�F"); scanf("%d",&b);

    int sum=0;
    int cnt=0;

    do{
        sum=sum+(a<=b?a:b)+cnt;
        cnt=cnt+1;    
    }while(cnt!=(a<=b?b-a+1:a-b+1)); 
    
    printf("%d�ȏ�%d�ȉ��̑S�����̘a��%d�ł��B\n",a<=b?a:b,a<=b?b:a,sum);

    return 0;
}