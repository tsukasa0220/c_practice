#include <stdio.h>

int main(void) {
    int no;
    printf("�P����W�܂ł̐�������͂��Ă�������:"); scanf("%d",&no);

    switch (no){
    case 1:puts("���z�n��P�f���́A�����ł��B"); break;
    case 2:puts("���z�n��Q�f���́A�����ł��B"); break;
    case 3:puts("���z�n��R�f���́A�n���ł��B"); break;
    case 4:puts("���z�n��S�f���́A�ΐ��ł��B"); break;
    case 5:puts("���z�n��T�f���́A�ؐ��ł��B"); break;
    case 6:puts("���z�n��U�f���́A�y���ł��B"); break;
    case 7:puts("���z�n��V�f���́A�V�����ł��B"); break;
    case 8:puts("���z�n��W�f���́A�C�����ł��B"); break;
    default :printf("���z�n��%d�f���́A�m���Ă��܂���B\n",no); break;
    }
    
    return 0;
}