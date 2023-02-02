#include <stdio.h>

int main(void) {
   int no;
   printf("0から999の整数を入力してください:"); scanf("%d",&no);

   if(no<0||no>=1000){
       puts("負の数と４桁以上の数には対応できません。");
   }else if(no%7==0||no%10==7||no/10%10==7||no/100%10==7){
       printf("%dは7の倍数か7が付きます。\n",no);
   }else{
       printf("%dは普通の数です。\n",no);
   }
    
    return 0;
}