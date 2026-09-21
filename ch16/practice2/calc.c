#include "calc.h"

int g_count=0;
int max_score(int arr[], int n){
    g_count++;
    int max=arr[0];//假设第一个数是最大值
    for(int i=1;i<n;i++){
        if(arr[i]>max){
          max=arr[i];
        }
    }
    return max;
}

double avg_score(int arr[], int n){
    g_count++;
    double sum=0.0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum/n;
}