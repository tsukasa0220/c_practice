#include <stdio.h>

int main(void) {
	
    int a,b,c;
    printf("�����P�F"); scanf("%d",&a);
    printf("�����Q�F"); scanf("%d",&b);
    printf("�����R�F"); scanf("%d",&c);

    printf("�ŏ��l��%d�ł��B\n",a<b?a:(b<c?b:c));
    
    return 0;
}