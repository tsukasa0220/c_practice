#include <stdio.h>

int main(void) {
   int no;
   printf("0����999�̐�������͂��Ă�������:"); scanf("%d",&no);

   if(no<0||no>=1000){
       puts("���̐��ƂS���ȏ�̐��ɂ͑Ή��ł��܂���B");
   }else if(no%7==0||no%10==7||no/10%10==7||no/100%10==7){
       printf("%d��7�̔{����7���t���܂��B\n",no);
   }else{
       printf("%d�͕��ʂ̐��ł��B\n",no);
   }
    
    return 0;
}