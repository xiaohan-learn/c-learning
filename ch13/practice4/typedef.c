/*目标：补上两个没练过的小点——typedef 给结构体起别名、结构体里套结构体。
用 typedef 定义两个结构体别名（这样后面就能直接写 Date / Student，不用每次 struct xxx）：
Date：year / month / day（年/月/日）
Student：name[50]、birthday（类型是 Date，这就是嵌套）、score
建 1~2 个 Student，给 birthday 也赋值（比如 {"张三", {2005,3,15}, 90}）
打印出来，重点要能访问到嵌套成员：stu.birthday.year
写一个函数 void print_stu(Student* s)，用指针 + -> 打印姓名、生日、成绩
（把 practice2 的指针套路用上）*/
#include <stdio.h>
#include <string.h>
typedef struct Date{
    int year;
    int month;
    int day;
}D;
typedef struct Student{
    char name[50];
    D birthday;
    int score;
}S;

void print_stu(S* a,int n);
int main(){
    S st1={"张三",{2003,11,11},90};
    S st2={"李四",{2004,12,12},80};
    S arr[]={st1,st2};
    print_stu(arr,2);
return 0;

}
void print_stu(S* a,int n){
    for(int i=0;i<n;i++){
        printf("姓名:%s ,生日:%d-%d-%d ,成绩:%d\n",a[i].name,
            a[i].birthday.year,a[i].birthday.month,a[i].birthday.day,
            a[i].score);
    }
}