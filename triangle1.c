#include <stdio.h>
int main(void) {
    int i, j, ln;

    printf("���̐�������͂��ĉ�����: ");
    scanf("%d", &ln);
   
    for (i = 1; i<=ln; i++) {
        for (j = 1; j<=(ln-i)*2+1; j+=2) {
            printf("%d", j%10);     
        }
        putchar('\n');
    }
    printf("end\n");
    return 0;
}