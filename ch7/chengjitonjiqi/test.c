 /*写 int max_score(int arr[], int n) 返回最高分
 写 double avg_score(int arr[], int n) 返回平均分
 main 中调用两函数并 printf 结果，gcc 编译运行
预期产出：可运行程序，输入样例后正确输出最高分与平均分*/
#include <stdio.h>
int max_score(int arr[], int n);
double avg_score(int arr[], int n);

int main()
{
    int scores[5];
    printf("请输入5个数字\n");
    for(int i=0;i<5;i++){
        scanf("%d",&scores[i]);    
    }

    int max=max_score(scores, 5);
    double avg=avg_score(scores, 5); 
    printf("最高分是%d\n",max);
    printf("平均分是%.2f\n",avg);
    return 0;
}

int max_score(int arr[], int n){
    int max=arr[0];//假设第一个数是最大值
    for(int i=1;i<n;i++){
        if(arr[i]>max){
          max=arr[i];
        }
    }
    return max;
}

double avg_score(int arr[], int n){
    double sum=0.0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum/n;
}