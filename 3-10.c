#include <stdio.h>

int main(void) {
	
int a,b,c;
puts("�O�̐�������͂���B");
printf("����A:"); scanf("%d",&a);
printf("����B:"); scanf("%d",&b);
printf("����C:"); scanf("%d",&c);

if (a==b&&a==c){
    puts("�O�̒l�͓������ł��B");
}else if (a==b||a==c||b==c){
    puts("��̒l���������ł��B");
}else{
    puts("�O�̒l�͈قȂ�܂��B");
}

    return 0;
}