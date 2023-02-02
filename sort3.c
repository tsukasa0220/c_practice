#include <stdio.h>

int main(void) {
   int no1,no2,no3;
   puts("三つの整数を入力してください。");
   printf("整数1:"); scanf("%d",&no1);
   printf("整数2:"); scanf("%d",&no2);
   printf("整数3:"); scanf("%d",&no3);

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
   printf("最大値は%d、真ん中の値は%d、最小値は%dです\n",max,mid,min);

    return 0;
}