#include <stdio.h>

#define MAX 50

/* 返回数组 arr 中前 n 个元素的最高分 */
int max_score(int *arr, int n) {
    int max;
    max=*arr;
    for(int *p=arr;p<arr+n;p++){
        if(*p>max)
        max=*p;   
    }
    return max;
    // TODO: 遍历 arr[0..n-1]，记录最大值并返回
}

/* 返回数组 arr 中前 n 个元素的平均分（用 double 返回） */
double avg_score(int*arr, int n) {
    double sum=0.0;
    for(int *p=arr;p<arr+n;p++){
        sum+=*p;
    }
    return sum/n;
    // TODO: 累加求和，再除以 n 返回平均分
}

/* 冒泡排序：把 arr 的前 n 个元素按从小到大升序排列（原地排） */
void bubble_sort(int *arr, int n) {
    for(int i=0;i<n-1;i++){
        for(int *p=arr;p<arr+n-i;p++){
            if(*p>*(p+1)){
             int temp=*p;
             *p=*(p+1);
             *(p+1)=temp;
            }
        }
    }
    // TODO: 外层循环控制轮数，内层循环相邻比较交换
    // 提示：每一轮把当前最大的“冒泡”到最后
}

int main() {
    int scores[MAX];
    int n;

    printf("请输入成绩个数(不超过%d): ", MAX);
    scanf("%d", &n);

    printf("请输入%d个成绩:\n", n);
    for (int *p=scores; p <scores+n; p++) {
        scanf("%d", p);
    }
    
    int max=max_score(scores,n);
    double avg=avg_score(scores,n);
    bubble_sort(scores,n);
    printf("最高分是%d\n",max);
    printf("平均分是%.2f\n",avg);
    printf("排序后的成绩列表是:\n");
    for(int i=0;i<n;i++){
        printf("%d ",scores[i]);
    }

    // TODO: 依次调用 max_score / avg_score / bubble_sort
    // 打印：最高分、平均分、排序后的成绩列表
    // 小挑战：排序后 scores[n-1] 是最高分、scores[0] 是最低分，能否打印“第 k 名”？

    return 0;
}
