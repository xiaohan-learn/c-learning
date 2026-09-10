#include <stdio.h>
int main(void)
{
    int n;
    double a=2,b=1;//a分子，d分母
    scanf ("%d",&n);
    double sum=0.0;
    int i;
    double t;
    for(i=1;i<=n;i++){
        sum+=a/b;
        t=a;
        a+=b;
        b=t;
    }
    printf ("%.2f\n",sum);
    return 0;
}