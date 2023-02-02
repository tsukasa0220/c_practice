#include <stdio.h>

int main(void) {
    int a,b;

    puts("二つの整数を入力せよ。");
    printf("整数a："); scanf("%d",&a);
	printf("整数b："); scanf("%d",&b);

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
    
    printf("%d以上%d以下の全整数の和は%dです。\n",low,high,sum);

    return 0;
}