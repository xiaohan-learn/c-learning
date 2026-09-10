#include <stdio.h>
int main(void)
{
    printf("输入在一行中给出1个正整数，单位是厘米:");
    int cm;
    scanf("%d",&cm);
    
    float m=cm/100.0;
    float total_foot=m/0.3048;
    
    int foot=total_foot;
    int inch=(total_foot-foot)*12; 
    
    printf("%d %d\n",foot,inch);
    return 0;
}