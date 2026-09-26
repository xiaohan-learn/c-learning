/* 练习6 简易成绩/通讯录存档
写什么
- 输入若干学生（struct + 枚举状态），写文件存档；程序重启后读文件还原列表。
- 重点：把 ch13 结构体 + ch15 枚举 + 今天文件 IO 串起来，做一个能「存/取」的小工具。*/
/*========== ch15 枚举：学生状态 ==========
========== ch13 结构体：学生信息 ==========
最多学生数量===========工具函数：读取一行字符串，自动去掉末尾回车换行
枚举转字符串，打印用=======添加学生=====打印全部学生
========= 文件IO：保存到文件 =========文件IO：从文件加载====main*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//枚举学生状态
typedef enum{
    STUDYING,//在读
    SUSPENDED,//休学
    GRADUATED//毕业
}STUSTATUS;
//结构体学生信息
typedef struct {
    int id;
    char name[50];
    char phone[30];
    float score;
    STUSTATUS status;
}STUDENT;
//最大学生数量
#define MAX_STU 100
STUDENT stulist[MAX_STU];
int stucount=0;
//读取一行字符串，自动去掉末尾换行符
void input_str(const char *prompt,char *buf,int len){
    printf("%s",prompt);
    if(fgets(buf,len,stdin)==NULL){
        buf[0]='\0';
        return ;
    }
    buf[strcspn(buf,"\n")]='\0';
}
//打印整数
int input_int(const char *prompt){
    char buf[64];
    input_str(prompt,buf,sizeof(buf));
    return atoi(buf);
}
//打印浮点数
float input_float(const char *prompt){
    char buf[64];
    input_str(prompt,buf,sizeof(buf));
    return (float)atof(buf);
}
//枚举转字符串，打印用
const char *enum_str(STUSTATUS s){
    switch(s){
        case STUDYING: return "在读";
        case SUSPENDED: return "休学";
        case GRADUATED: return "毕业";
        default : return "未知";
    }
}
//添加学生
void add(void){
    if(stucount>=MAX_STU){
        printf("人数已满\n");
        return;
    }
    STUDENT s;
    int op;
    printf("添加学生信息\n");
    s.id=input_int("学号");
    input_str("姓名:",s.name,sizeof(s.name));
    input_str("电话:",s.phone,sizeof(s.phone));
    s.score=input_float("成绩:");
    op=input_int("状态(0在读,1休学,2毕业) :");
    s.status=(STUSTATUS)op;
    stulist[stucount]=s;
    stucount++;
    printf("添加成功\n");
}
//打印全部学生
void showall(void){
    printf("------加载%d名学生信息-----\n",stucount);
    for(int i=0;i<stucount;i++){
        STUDENT *p=&stulist[i];
        printf("[%d],学号:%d\n 姓名:%s\n 电话:%s\n 成绩:%.1f\n 状态:%s\n",
        i+1,p->id,p->name,p->phone,p->score,enum_str(p->status));
    }
}
//保存到文件
void savefile(const char *filename){
    FILE *fp=fopen(filename,"wb");
    if(fp==NULL){
        perror("wb fopen error");
        return ;
    }
    fwrite(&stucount,sizeof(int),1,fp);
    fwrite(stulist,sizeof(STUDENT),stucount,fp);
    fclose(fp);
    fp=NULL;
    printf("数据已保存到%s\n",filename);
}
//从文件中加载
void loadfile(const char *filename){
    FILE *fp=fopen(filename,"rb");
    if(fp==NULL){
        perror("rb fopen error");
        return ;
    }
    fread(&stucount,sizeof(int),1,fp);
    fread(stulist,sizeof(STUDENT),stucount,fp);
    fclose(fp);
    fp=NULL;
    printf("已成功加载%d条学生信息",stucount);
}

int main(){
    int choice;
    const char *filename="student.dat";
    while(1){
        printf("------学生简易信息通讯录-----\n");
        printf("1.添加学生信息\n");
        printf("2.查看全部学生信息\n");
        printf("3.保存数据到文件\n");
        printf("4.从文件中加载数据\n");
        printf("0.退出通讯录\n");

        choice=input_int("请输入选项：");
        switch(choice){
            case 1:add();break;
            case 2:showall();break;
            case 3:savefile(filename);break;
            case 4:loadfile(filename);break;
            case 0:
            savefile(filename);
            printf("退出通讯录\n");break;
            default :printf("输入选项数字错误\n");return 0;
        }

    }
    return 0;
}





