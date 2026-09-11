#include <stdio.h>
void swap(int a,int b);
int main()
{
    int a=8;
    int b=9;
    swap(a,b);
   printf("a=%d,b=%d\n",a,b);
    return 0;
}
void swap(int a,int b)
{
    int t=a;
    a=b;
    b=t;
}