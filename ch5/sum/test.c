#include <stdio.h>
void sum(int begin,int end)
{
    int i=0;
    int sum =0;
    for(i=begin;i<=end;i++)
    {
        sum+=i;
    }
    printf ("从%d到%d的和为%d\n",begin,end,sum);
   
}

    int main(){
        sum(1,10);
        sum(30,40);
        sum(60,70);
        return 0;
    }
