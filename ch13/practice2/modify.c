/*用结构体指针 + -> 访问成员；写 void raise(struct Student* s, int add) 通过指针改成绩*/
#include <stdio.h>
struct student {
    int score;
};

void raise(struct student*s,int add);

int main(){
    struct student st={100};
    printf("修改前的成绩为%d\n",st.score);
    raise(&st,100);
    printf("修改后的成绩为%d\n",st.score);
    return 0;
}

void raise(struct student* s,int add){
    s->score+=add;
}
