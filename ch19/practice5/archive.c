/*练习5 批量存档（必做）
写什么
- `struct Student arr[N]`，循环 `fwrite` 多个 → 读回循环 `fread`，验证顺序一致。*/
#include <stdio.h>

struct student {
    int id;
    char name[50];
    float score;
};

int main(){
    //二进制写
    FILE *fp=fopen("test.txt","wb");
    if(fp==NULL){
        perror("fp fopen error");
        return 1;
    }

    struct student arr[]={
        {101,"zhangsan",90.5f},
        {102,"lisi",78.5f},
        {103,"wangwu",89.6f}
    };
    int wb_count=sizeof(arr)/sizeof(arr[0]);
    int wb_ret=fwrite(arr,sizeof(struct student),wb_count,fp);
    if(wb_ret!=wb_count){
        perror("fwrite error");
        fclose(fp);
        return 1;
    }

    fclose(fp);
    fp=NULL;
    printf("成功写入%d个学生信息\n",wb_count);

    //二进制读
    FILE *rp=fopen("test.txt","rb");
    if(rp==NULL){
        perror("rp fopen error");
        return 1;
    }

    struct student s;
    while(fread(&s,sizeof(struct student),1,rp)==1){
        printf("id: %d,name: %s, score: %.2f\n",s.id,s.name,s.score);
    }

    fclose(rp);
    rp=NULL;
   

    return 0;

}