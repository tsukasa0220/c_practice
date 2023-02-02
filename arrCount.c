#include <stdio.h>

#define NUMBER 10

int main(void) 
{
	int v[NUMBER] = {-17, 92, 10, -98, 1, -7, 114, -8, 0, 76};
	int sum = 0;

	for (int i = 0; i < NUMBER; i++) {
		sum += v[i];
		printf("v[0] ~ v[%d]‚Ü‚Å‚Ì˜a‚Í%d‚Å‚·B\n", i, sum);
	}
	
    return 0;
}