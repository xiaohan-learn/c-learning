/*   *(arr+i) 为什么等于 arr[i]   */
#include<stdio.h>
int main()
{
    int arr[6]={1,3,5,7,9,0};
    int len=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<len;i++){
        printf("*(arr+i)=%d\t",*(arr+i));
        printf("arr[i]=%d\n",arr[i]);
    }
    return 0;
}