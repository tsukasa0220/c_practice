#include <stdio.h>

int main(void) {
    int a,b;

    puts("��̐�������͂���B");
    printf("����a�F"); scanf("%d",&a);
	printf("����b�F"); scanf("%d",&b);

    int sum=0;
    int cnt=0;
    int low=a;
    int high=b;
    if(a>b){
        high=a;
        low=b;
    }

    do{
        sum+=low+cnt;
        cnt++;    
    }while(cnt!=high-low+1); 
    
    printf("%d�ȏ�%d�ȉ��̑S�����̘a��%d�ł��B\n",low,high,sum);

    return 0;
}