#include<stdio.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    //int fu=0;
    if(n<0){
        n=-n;
        printf("fu "); 
    }
    int mask=1;
    int t=n;
    while(t>9){
        t/=10;
        mask*=10;
    }
    while(mask>0){
        int d=n/mask;
        switch (d)
        {
        case 0:  printf("ling");  break;
        case 1:  printf("yi");  break;
        case 2:  printf("er");  break;
        case 3:  printf("san");  break;
        case 4:  printf("si");  break;
        case 5:  printf("wu");  break;
        case 6:  printf("liu");  break;
        case 7:  printf("qi");  break;
        case 8:  printf("ba");  break;
        case 9:  printf("jiu");  break;
    
        }if(mask>9){printf (" ");}
        n%=mask;
        mask/=10;
    }

    return 0;
}