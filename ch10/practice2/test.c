/*用指针访问/遍历数组的几种写法*/
#include<stdio.h>
int main()
{
    int arr[5]={2,4,6,8,10};
    int len=sizeof(arr)/sizeof(int);

    for(int i=0;i<len;i++){
        printf("%d\t",*(arr+i));
    }
    printf("\n");
    for(int *p=arr;p<arr+len;p++){
        printf("%d\t",*p);
    }
    return 0;
}