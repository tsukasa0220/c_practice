#include <stdio.h>

int main(void) {
   int shou;
   int amari;
   for(int i=1;i<=60;i++){
      shou=60/i;
      amari=60%i;
      if(amari){
         printf("60=%d*%d+%d\n",i,shou,amari);
      }else{
         printf("60=%d*%d\n",i,shou);
      }
      
   }
   return 0;
}
