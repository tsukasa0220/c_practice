#include <stdio.h>

int main(void) {
   
   int no;
   printf("���̐�������͂���:"); scanf("%d",&no);
   int tmp=no;
   while(no>=1){
       printf("%d",no--);
   } 
   if(tmp>0){
       printf("\n");
   }
    return 0;
}