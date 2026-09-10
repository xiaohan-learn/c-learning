#include <stdio.h>
int main (void)
{
    int x;
    scanf ("%d",&x);
    int one=0,two=0,five=0;
    int found=0;

    for (one=0;one<x*10;one++){
        for (two=0;two<x*10/2;two++){
            for(five=0;five<x*10/5;five++){
                if(one+two*2+five*5==x*10){
                    printf ("%d个1角加%d个2角加%d个5角=%d元\n",one,two,five,x);
                    //goto out;
                   found=1;break;
                }
            }
            if (found==1) break;
        }
        if (found==1) break;
    }
    //out:
    return 0;
}