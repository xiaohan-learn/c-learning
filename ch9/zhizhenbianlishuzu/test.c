#include <stdio.h>
int main()
{
    int a[]={2,4,6,8,10};
    int len=sizeof(a)/sizeof(int);

    for(int *p=a;p<a+len;p++){
        printf("%d ",*p);
    }
    return 0;
}