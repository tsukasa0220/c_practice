#include <stdio.h>

int main(void) {
	
int month;
printf("�����ł����F"); scanf("%d",&month);

switch (month){
    case 1:printf("%d���͓~�ł��B\n",month); break;
    case 2:printf("%d���͓~�ł��B\n",month); break;
    case 3:printf("%d���͏t�ł��B\n",month); break;
    case 4:printf("%d���͏t�ł��B\n",month); break;
    case 5:printf("%d���͏t�ł��B\n",month); break;
    case 6:printf("%d���͉Ăł��B\n",month); break;
    case 7:printf("%d���͉Ăł��B\n",month); break;
    case 8:printf("%d���͉Ăł��B\n",month); break;
    case 9:printf("%d���͏H�ł��B\n",month); break;
    case 10:printf("%d���͏H�ł��B\n",month); break;
    case 11:printf("%d���͏H�ł��B\n",month); break;
    case 12:printf("%d���͓~�ł��B\n",month); break;
    default:printf("%d���͂���܂����B\n",month); break;
}
    
    return 0;
}