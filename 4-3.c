#include <stdio.h>

int main(void) {
   
   int no;
   printf("³‚Ì®”‚ð“ü—Í‚¹‚æ:"); scanf("%d",&no);
   int tmp=no;
   while(no>=0){
       printf("%d",no);
       no--;
   } 
   if(tmp>=0){
       printf("\n");
   }
    return 0;
}