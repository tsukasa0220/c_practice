#include <stdio.h>

int main(void) {
    int no;
    do{
        printf("1����8�̐�������͂��Ă�������:");
        scanf("%d",&no);
        switch(no){
            case 1:puts("���z�n��1�f���́A�����ł��B"); break;
            case 2:puts("���z�n��2�f���́A�����ł��B"); break;
            case 3:puts("���z�n��3�f���́A�n���ł��B"); break;
            case 4:puts("���z�n��4�f���́A�ΐ��ł��B"); break;
            case 5:puts("���z�n��5�f���́A�ؐ��ł��B"); break;
            case 6:puts("���z�n��6�f���́A�y���ł��B"); break;
            case 7:puts("���z�n��7�f���́A�V�����ł��B"); break;
            case 8:puts("���z�n��8�f���́A�C�����ł��B"); break;
        }
    }while (no<1||no>8);

    return 0;
}