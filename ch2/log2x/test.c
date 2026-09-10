#include <stdio.h>
int main(void)
{
    int x=0,ret=0;
    scanf ("%d",&x);
    while(x>1){
        x/=2;
        ret++;
    }
    printf ("%d\n",ret);
    return 0;
}