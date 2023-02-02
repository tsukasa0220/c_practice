#include <stdio.h>

#define NUMBER1 7
#define NUMBER2 8
#define NUMBER3 2


int countNegativeMult3(const int vc[], int no)
{
    int tmp;
    int cnt = 0;
    for (int i = 0; i < no; i++) {
        if (vc[i] < 0 && -vc[i] % 3 == 0) {
            cnt++;
        }
    }
    return cnt;

}

int main(void)
{
    int arr1[NUMBER1] = {1, 2, -3, -4, 5, -6, -7};     
    int arr2[NUMBER2] = {-3, 6, 7, -9, -8, 2, 0, -15}; 
    int arr3[NUMBER3] = {-2, 3};
    int cnt;

    cnt = countNegativeMult3(arr1, NUMBER1);
    printf("arr1‚Ì•‰‚Ì 3 ‚Ì”{”‚ÌŒÂ”‚Í%dŒÂ‚Å‚·B\n", cnt);
    cnt = countNegativeMult3(arr2, NUMBER2);
    printf("arr2‚Ì•‰‚Ì 3 ‚Ì”{”‚ÌŒÂ”‚Í%dŒÂ‚Å‚·B\n", cnt);
    cnt = countNegativeMult3(arr3, NUMBER3);
    printf("arr3‚Ì•‰‚Ì 3 ‚Ì”{”‚ÌŒÂ”‚Í%dŒÂ‚Å‚·B\n", cnt);

    return 0;
}