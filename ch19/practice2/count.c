/*写什么
- `fopen` 一个已知文本，`fgetc` 逐字符读，统计字符数 / 行数（遇 `\n` +1）。
验收输出
- 对一个已知文本，手算行数/字符数核对一致。
坑预警
- 别用 `feof()` 控制循环（会多读一次）；用 `while((c=fgetc(fp))!=EOF)`。
- `fgetc` 返回 `int`（要能装下 EOF），别用 `char` 接。*/
#include <stdio.h>

int main(){
    FILE *fp=fopen("D:\\code_c\\ch19\\practice1\\test.txt","r");
    if(fp==NULL){
        perror("fopen error");
        return 1;
    }

    int ch;
    int char_count=0;
    int line_count=0;
    while((ch=fgetc(fp))!=EOF){
        char_count++;
        if(ch=='\n'){
            line_count++;
        }
    }

    printf("字符数=%d\n",char_count);
    printf("行数=%d\n",line_count);

    fclose(fp);
    fp=NULL;

    return 0;
}