#include <stdio.h>



int arr[10] = {7, -2, 0, 4, 13, 2, 9, -8, 1, 3};
int no = 10;

void rrot2(int va[], int no)
{
    int tmp1 = va[no - 2];
    int tmp2 = va[no - 1];

    for (int i = no - 1; i > 0; i--) {
        va[i] = va[i - 2];
    }

    va[0] = tmp1;
    va[1] = tmp2;
}
void print_array(const int v[], int n)
{
	printf("{ ");
	for (int i = 0; i < n; i++) {
		printf("%d ", v[i]);
    }    
	printf("}\n");
}

int main(void) {
    int i;
    printf("適用前: ");
    print_array(arr, no);
    putchar('\n');
    rrot2(arr, no);
    printf("適用後: ");
    print_array(arr, no);
    putchar('\n');

    return 0;
}