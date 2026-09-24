/* 练习1 写 + 读文本（必做）
写什么
- 用 `fopen("test.txt","w")` → `fprintf`/`fputs` 写几行（如学生姓名/成绩）→ `fclose`。
- 再用 `fopen("test.txt","r")` → `fgets` 逐行读到缓冲区 → 打印 → `fclose`。
验收输出
- 读出来的内容 == 写进去的内容。
坑预警
- 写用 `"w"` 会**清空**原文件；读用 `"r"` 文件不存在则 fopen 返 NULL（必须判空，别解引用空指针）。
- `fgets(buf, sizeof(buf), fp)` 读不到时返 NULL，用它控制循环。*/
#include <stdio.h>

        //--------------字符串读写------------
struct student {
    char name[50];
    int score;
};
int main(){
    //写
    FILE *fp=fopen("test.txt","w");
    if(fp==NULL){
        perror("fopen error");
        return 1;
    }

    struct student s[3]={{"zhangsan",100},{"lisi",87},{"wangwu",95}};
    int i;
    for( i=0;i<3;i++){
        fprintf(fp,"%s %d\n",s[i].name,s[i].score);
    }

    fclose(fp);
    fp=NULL;

    //读

    FILE *rp=fopen("test.txt","r");
    if(rp==NULL){
        perror("fopen error");
        return 1;
    }

    char buf[100];
    while(fgets(buf,sizeof(buf),rp)!=NULL){
        printf("%s",buf);
    }

    fclose(rp);
    rp=NULL;

    return 0;
}

     //--------------字符读写------------

// int main(){
//     //写
//     FILE *fp=fopen("test.txt","w");
//     if(fp==NULL){
//         perror("fopen error");
//         return 1;
//     }

//     for(char i='a';i<='z';i++){
//         fputc(i,fp);
//     }

//     fclose(fp);
//     fp=NULL;

//     //读
//     FILE *rp=fopen("test.txt","r");
//     if (rp==NULL){
//         perror("fopen error");
//         return 1;
//     }

//     int ch;//fgetc返回值类型是 int！不是 char！
//     while((ch=fgetc(rp))!=EOF){
//         printf("%c ",ch);
//     }

//     fclose(rp);
//     rp=NULL;

//     return 0;
// }