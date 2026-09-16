/* 练习：手写 my_strchr（不调库，自己用指针遍历实现）
   功能：在字符串 str 中找字符 c 第一次出现的位置
     找到   -> 返回指向该字符的指针
     没找到 -> 返回 NULL（空指针）
   要求：不能用 <string.h> 的 strchr，必须自己遍历 */
#include <stdio.h>

char* my_strchr(const char* str, char c) {
    const char* p=str;
    while(*p!='\0'){
        if(*p==c){
            return (char*)p;//找到目标字符，强制转char*返回（兼容原strchr原型）
        }
        p++;
    }
    return NULL;

}

int main(void) {
    char a[] = "hello";

    char* p = my_strchr(a, 'l');
    if (p != NULL)
        printf("找到 'l'，其后字符串: %s\n", p);   // 期望: llo
    else
        printf("未找到 'l'\n");

    char* p2 = my_strchr(a, 'z');
    if (p2 != NULL)
        printf("找到 'z'，其后字符串: %s\n", p2);
    else
        printf("未找到 'z'\n");                     // 期望走这里

    char* p3 = my_strchr(a, 'h');
    if (p3 != NULL)
        printf("找到 'h'，其后字符串: %s\n", p3);  // 期望: hello
    else
        printf("未找到 'h'\n");

    return 0;
}
