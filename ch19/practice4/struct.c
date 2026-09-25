/* 练习4 结构体写入文件（必做）
写什么
- 定义 `struct Student{int id; char name[20]; float score;}`。
- `fopen("stu.dat","wb")` → `fwrite(&s, sizeof(s), 1, fp)` → `fclose`。
- 再 `"rb"` → `fread(&s, sizeof(s), 1, fp)` 读回 → 打印核对。
验收输出
- 读回的 id/name/score 与写入一致。
坑预警
- 二进制**必须用 `"b"`**；`fwrite` 返回成功写入的元素个数，应检查 `==1`。*/
#include <stdio.h>

struct Student {
    int id;
    char name[20];
    float score;
};

int main(){
    FILE *fp=fopen("test.txt","wb");
    if(fp==NULL){
        perror("fp fopen error");
        return 1;
    }

    struct Student s={101,"zhangsan",90.5f};
    int ret=fwrite(&s,sizeof(struct Student),1,fp);
    if(ret!=1){
        perror("fwrite error");
        return 1;
    }


    fclose(fp);
    fp=NULL;


    FILE *rp=fopen("test.txt","rb");
    if (rp==NULL){
        perror("rp fopen error");
        return 1;
    }

    struct Student a={0};
    int ret1=fread(&a,sizeof(struct Student),1,rp);
    if(ret1!=1){
        perror("fread error");
        return 1;
    }
 
    fclose(rp);
    rp=NULL;

    printf("id=%d,name=%s,score=%.2f",a.id,a.name,a.score);

    return 0;
}