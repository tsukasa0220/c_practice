#include <stdio.h>

int main(void) {
   int no1,no2,no3;
   puts("�O�̐�������͂��Ă��������B");
   printf("����1:"); scanf("%d",&no1);
   printf("����2:"); scanf("%d",&no2);
   printf("����3:"); scanf("%d",&no3);

   int max=no1,mid=no2,min=no3,tmp;
   if(no2>max){
       tmp=max;
       max=no2;
       mid=tmp;
   }
   if(no3>max){
       tmp=max;
       max=no3;
       min=tmp;
   }
   if(mid<min){
       tmp=mid;
       mid=min;
       min=tmp;
   }
   printf("�ő�l��%d�A�^�񒆂̒l��%d�A�ŏ��l��%d�ł�\n",max,mid,min);

    return 0;
}