/*逐字符比较，返回大小关系*/
#include <stdio.h>
int my_strcmp(const char*str1,const char*str2);
int main(){
    char s1[]="abc";
    char s2[]="abc";
    int ret=my_strcmp(s1,s2);
    printf("%d\n",ret);
    return 0;
}
int my_strcmp(const char*str1,const char*str2){
    int idx=0;
    while(str1[idx]==str2[idx]&&str1[idx]!='\0'){
        idx++;
            }
            return str1[idx]-str2[idx];
}