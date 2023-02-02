#include <stdio.h>

int main(void) {
	
     int a,b,c,d;
    printf("整数１："); scanf("%d",&a);
    printf("整数２："); scanf("%d",&b);
    printf("整数３："); scanf("%d",&c);
    printf("整数４："); scanf("%d",&d);

    int max=a;
    if (b>max){
       max=b;  
    } 
    if (c>max){
       max=c;  
    } 
    if (d>max){
       max=d; 
    }
    printf("最大値は%dです。\n",max);
   
    return 0;
}