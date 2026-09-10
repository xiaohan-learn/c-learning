#include <stdio.h>
int main (void)
{
    int n=0;
    scanf ("%d",&n);
    int i=0;
    double sum=0.0;
    double sign=1.0;
    for (i=1;i<=n;i++){
        sum+=sign/i;
        sign=-sign;

    }
    printf ("f(%d)=%f",n,sum);
    return 0;
}