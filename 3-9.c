#include <stdio.h>

int main(void) {
	
    int a,b,c;
    printf("整数１："); scanf("%d",&a);
    printf("整数２："); scanf("%d",&b);
    printf("整数３："); scanf("%d",&c);

    printf("最小値は%dです。\n",a<b?a:(b<c?b:c));
    
    return 0;
}