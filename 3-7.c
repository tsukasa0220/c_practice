#include <stdio.h>

int main(void) {
	
     int a,b,c,d;
    printf("�����P�F"); scanf("%d",&a);
    printf("�����Q�F"); scanf("%d",&b);
    printf("�����R�F"); scanf("%d",&c);
    printf("�����S�F"); scanf("%d",&d);

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
    printf("�ő�l��%d�ł��B\n",max);
   
    return 0;
}