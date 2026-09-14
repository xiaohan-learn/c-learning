/*同一个函数分别用 void f(int arr[]) 和 void f(int *arr) 声明，
调用都用 f(scores)，验证两者完全等价。
目的：建立"数组传参即传指针"的直觉。*/
#include <stdio.h>

int f1(int arr[],int len);
int f2(int *arr,int len);
int main()
{
    int scores_min[5]={45,67,58,98,73};
    int len=5;
    int min1=f1(scores_min,len);
    printf("调用数组=%d\n",min1);
    int min2=f2(scores_min,len);
    printf("调用指针=%d\n",min2);

    return 0;
}

int f1(int arr[],int len){
    int min1=arr[0];
    for(int i=1;i<len;i++){
        if(arr[i]<min1){
            min1=arr[i];
        }
    }
    return min1;
}

int f2(int*arr,int len){
    int min2=*arr;
    for(int *p=arr;p<arr+len;p++){
        if(*p<min2){
            min2=*p;
        }
    }
    return min2;
}