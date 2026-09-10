#include <stdio.h>
int main (void)
{
    int a,b;//a分子，b分母
    scanf("%d/%d",&a,&b);
    int r;
    int e=a;
    int f=b;
    while(f!=0){
        r=e%f;
        e=f;
        f=r;
    }
    printf("%d/%d",a/e,b/e);
    return 0;
}