/*练习3 复制文件（可选）
写什么
- `fopen` 两个句柄（src `"rb"`, dst `"wb"`），逐块 `fread`/逐字符 `fgetc` 写入 dst。
坑预警
- 两个 `FILE*` 别搞混；最后都 `fclose`。*/
#include <stdio.h>

int main(){
    FILE *src=fopen("D:\\code_c\\ch19\\practice1\\test.txt","rb");
    if(src==NULL){
        perror("src fopen error");
        return 1;
    }

    FILE *dst=fopen("test.txt","wb");
    if(dst==NULL){
        perror("dst fopen error");
        return 1;
    }

    int ch;
    while((ch=fgetc(src))!=EOF){
        fputc(ch,dst);
    }

    printf("复制完成");

    fclose(src);
    fclose(dst);
    src=NULL;
    dst=NULL;

    return 0;

}