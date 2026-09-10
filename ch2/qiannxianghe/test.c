#include <stdio.h>
int main (void)
{
    int n=0;
    scanf ("%d",&n);
    int i=0;
    double sum=0.0;
    for (i=1;i<=n;i++){
        sum+=1.0/i;
        
    }
    printf ("f(%d)=%f\n",n,sum);
    return 0;
}