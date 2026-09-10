#include <stdio.h>
int main (void)
{
    int x;
    scanf ("%d",&x);
    int one=0,two=0,five=0;
    int total=x*10;//总角数

    for (one=0;one<total;one++){
        for (two=0;two<total/2;two++){
            for(five=0;five<total/5;five++){
                if(one+two*2+five*5==total){
                    printf ("%d个1角加%d个2角加%d个5角=%d元\n",one,two,five,x);
                }
            }
        }
    }
    return 0;
}