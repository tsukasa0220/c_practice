#include <stdio.h>

int main(void) {
    int a,b;

    puts("二つの整数を入力せよ。");
    printf("整数a："); scanf("%d",&a);
	printf("整数b："); scanf("%d",&b);

    int sum=0;
    int cnt=0;

    do{
        sum=sum+(a<=b?a:b)+cnt;
        cnt=cnt+1;    
    }while(cnt!=(a<=b?b-a+1:a-b+1)); 
    
    printf("%d以上%d以下の全整数の和は%dです。\n",a<=b?a:b,a<=b?b:a,sum);

    return 0;
}