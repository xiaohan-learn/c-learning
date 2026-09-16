/* ============================================================
   ch12 字符串与指针 · 练习1：my_strlen（模板 / TEMPLATE）
   ------------------------------------------------------------
   这个文件是「完整模板」，请照它的结构，自己写出后面三个：
     practice2_my_strcpy.c    —— my_strcpy(char *dst, const char *src)
     practice3_my_strcmp.c    —— my_strcmp(const char *s1, const char *s2)
     practice4_str_traverse.c —— 遍历打印每个字符的「地址 + 值」

   每个文件都长这样（照抄这个骨架，函数体你自己写）：
     1) 顶部注释：写清楚「这个练习练什么」
     2) #include <stdio.h>
     3) 你自己写的函数：先想清「参数是什么、返回什么」
     4) main()：写 2~3 组测试用例，并打印「期望结果」方便核对
   ============================================================ */

#include <stdio.h>

/* 返回字符串 s 的长度（不含 '\0'），不使用库函数 strlen
   用 const 表示函数不会修改 s —— 这是个好习惯 */
int my_strlen(const char*str);
int main(int argc,char const *argv[])
{
    char s[]="hello";
    char a[]="123456";
    printf("s的长度是%d\n",my_strlen(s));
    printf("a的长度是%d\n",my_strlen(a));
    return 0;
}

int my_strlen(const char*str){
    const char*p=str;
    while(*p!='\0'){
        p++;
    }
    return p-str;
}