#include <stdio.h>
int main(void)
{
    int x=0,t=0;
   scanf ("%d",&x);
    int mask=1;
    t=x;
    while(t>9){
        t/=10;
        mask*=10;
        
    }
      printf ("x=%d,mask=%d\n",x,mask);
    do{
        int d=x/mask;
        printf ("%d",d);
        if (mask>9){printf (" ");}
        x%=mask;
        mask/=10;
        
    }while(mask>0);
    printf("\n");
    return 0;
}