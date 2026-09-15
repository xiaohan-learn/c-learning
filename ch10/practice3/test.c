/*指针版"数组逆序"​（首尾各放一个指针，往中间交换）*/
#include<stdio.h>
void reverse(int *left,int *right);

int main()
{
    int arr[5]={1,3,5,7,9};
    int len=sizeof(arr)/sizeof(int);
    reverse(arr,(arr+len-1));
    for(int i=0;i<len;i++){
    printf("%d\t",*(arr+i));
    }
    return 0;
}

void reverse(int *left,int *right){
    int temp;
    while(left<right){
        temp=*left;
        *left=*right;
        *right=temp;
        left++;
        right--;
    }
}