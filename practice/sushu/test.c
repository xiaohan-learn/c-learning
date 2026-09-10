#include <stdio.h>
int main (void)
{
    int x=0;
    scanf ("%d",&x);
    int i=0;
    int isprime=1;//x是素数
    
    for (i=2;i<x;i++){
        if (x%i==0)
        {
            isprime=0;//x不是素数
            break;
        }
    }
    if (isprime==1){printf ("%d是素数\n",x);}
    else {printf ("%d不是素数\n",x);}
    return 0;
}