#include <stdio.h>

#define M 6 
#define N 9

int main(void) 
{
	int data[M][N] =  {
    { 1, 1, 1, 7, 7, 7, 1, 1, 1 },
    { 1, 1, 1, 7, 7, 7, 1, 1, 1 },
    { 1, 1, 1, 7, 7, 7, 1, 1, 1 },
    { 1, 1, 1, 7, 7, 7, 1, 1, 1 },
    { 1, 1, 1, 7, 7, 7, 1, 1, 1 },
    { 1, 1, 1, 7, 7, 7, 1, 1, 1 } };

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				switch (data[i][j]) {
					case 0 : printf("\033[90m¡\033[39m"); break;
					case 1 : printf("\033[91m¡\033[39m"); break;
					case 2 : printf("\033[92m¡\033[39m"); break;
					case 3 : printf("\033[93m¡\033[39m"); break;
					case 4 : printf("\033[94m¡\033[39m"); break;
					case 5 : printf("\033[95m¡\033[39m"); break;
					case 6 : printf("\033[96m¡\033[39m"); break;
					case 7 : printf("\033[97m¡\033[39m"); break;
					default : printf(" "); break;
				}
			}
			putchar('\n');
		}

    return 0;
}