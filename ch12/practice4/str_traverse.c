/*遍历打印每个字符的地址+值，直观看到 \0*/
#include<stdio.h>
int main(){
    char str[]="1234567";
    int len=sizeof(str)/sizeof(str[0]);
    for(int i=0;i<len;i++){
        printf("%p %c\n",&str[i],str[i]);
       
    }
    return 0;

}
