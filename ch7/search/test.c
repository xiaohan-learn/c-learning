#include <stdio.h>
int search(int key,int arr[],int length);
int main()
{
     int arr[] = {2, 4, 6, 7, 1, 3, 5, 9, 11, 13, 23, 14, 32};
    int x;
    scanf("%d",&x);
    int log=search(x,arr,sizeof(arr)/sizeof(arr[0]));
    if(log!=-1){
        printf("%d在%d的位置上\n",x,log);
    }else{
        printf("%d不存在\n",x);
    }
    return 0;
}

int search(int key,int arr[],int length){
    int ret=-1;
    for(int i=0;i<length;i++){
        if(arr[i]==key){
        ret=i;
        break;
        }
    }
    return ret;
}