#include <stdio.h>

int main(void) {
	
int n;
printf("��������͂���F"); scanf("%d",&n);

switch (n%2){
    case 0:puts("���̐��͋����ł��B"); break;
    default:puts("���̐��͊�ł��B"); break;
}
    return 0;
}