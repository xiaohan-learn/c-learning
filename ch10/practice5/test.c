/*对比"数组下标写法"和"指针写法"，写一句话总结差异*/
#include<stdio.h>
int main()
    {
        int arr[5]={1,3,5,7,9};
        int i=2;

        printf("%d\n",arr[i]);

        printf("%d\n",*(arr+i));
    }
