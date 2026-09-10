#include <stdio.h>
int main()
{
    printf ("请分别输入两个正整数：");
    int a;
    int b;
    scanf ("%d %d",&a,&b);
    int c=a+b;
    int d=a-b;
    int e=a*b;
    int f=a/d;
    printf ("%d+%d=%d\n",a,b,c);
    printf ("%d-%d=%d\n",a,b,d);
    printf ("%d*%d=%d\n",a,b,e);
    printf ("%d/%d=%d\n",a,b,f);
    return 0;

    


}