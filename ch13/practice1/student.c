/*定义 struct Student（姓名/学号/成绩），建 3 个元素的结构体数组，遍历打印*/
#include <stdio.h>
#include<string.h>

struct  student
{
    char name[100];
    char num[100];
    int grade;
};

int main(){
    struct student stu1={"张三","24031150101",100};
    struct student stu2={"李四","24031150102",200};
    struct student stu3={"王五","24031150103",300};

    struct student arr[3]={stu1,stu2,stu3};
    for(int i=0;i<3;i++){
        printf("姓名:%s,学号:%s,成绩:%d\n",arr[i].name,arr[i].num,arr[i].grade);
    }
    return 0;
    
}
