#include <stdio.h>
#include <string.h>
int main(int argc,char const *argv[])
{
    (void)argc;
    (void)argv;
 
    char a[]="hello";
    char *p=strchr(a,'l');
    char *p1=strrchr(a,'l');
     //p=strchr(p+1,'l');
    printf("%s\n",p);
    printf("%s",p1);
    return 0;
}