/*结构体数组遍历：算平均分、找最高分学生（综合 practice1+2）*/
/*目标：把 practice1 的"结构体数组"和 practice2 的"结构体指针传参"合起来练一遍。
要求
定义 struct Student：char name[50]; char num[20]; int score;
建一个数组（3~5 个学生，数据你直接写死在代码里即可，先不练输入）
写一个函数 void print_top(struct Student* arr, int n)，用指针方式遍历数组
（arr[i] 或 *(arr+i) 都行），做两件事：累加求平均分，打印
找出 score 最高的那个学生，打印他的姓名、学号、成绩
main 里建数组 → 调用 print_top(stu, 人数) → 看到结果*/
#include <stdio.h>
#include <string.h>
struct student{
    char name[50];
    char num[20];//学号
    int score;
};
void print_top(struct student*arr,int n);

int main()
{
    struct student st1={"张三","001",70};
    struct student st2={"李四","002",90};
    struct student st3={"王五","003",80};
    struct student a[3]={st1,st2,st3};
    print_top(a,3);


    return 0;
}

void print_top(struct student* arr,int n ){
    int i;
    double sum=0.0;
    struct student max=arr[0];
    for(i=0;i<n;i++){
        sum+=arr[i].score;
        if(arr[i].score>max.score){
            max=arr[i];
        }
    }
    double avg=sum/n;
    printf("平均分为%.2f\n",avg);
    printf("成绩最高的学生姓名：%s 学号：%s 成绩：%d\n",max.name,max.num,max.score);
}


