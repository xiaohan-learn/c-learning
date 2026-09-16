/*指针把 src 拷到 dst（含 \0）*/
#include<stdio.h>
char* my_strcpy(char*str1,const char*str2);
int main()
{
    char s1[]="1234";
    char s2[]="567";
    my_strcpy(s1,s2);
    printf("拷贝后s1=%s",s1);
    return 0;
}

char* my_strcpy(char*str1,const char*str2){
    int idx=0;
    while(str2[idx]!='\0'){
        str1[idx]=str2[idx];
        idx++;
    }
    str1[idx]='\0';
    return str1;
}