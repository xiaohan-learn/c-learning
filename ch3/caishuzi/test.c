#include <stdio.h>
int main(void)
{
    int ran,n;//随机数，最大次数n
    scanf ("%d %d",&ran,&n);
    int guess;//每次猜的数字
    int cnt=0;//猜的次数
    int finish=0;

    while(!finish){
        scanf ("%d",&guess);
       if(guess<0){
        printf ("Game Over\n");
        break;
       } 
       cnt++;
       if(guess>ran){
        printf("Too big\n");
       }else if(guess<ran){
        printf ("Too small\n");
       }else{
       if(cnt==1){
        printf ("Bingo!\n");
       }else if(cnt<3){
        printf ("Lucky You!\n");
       }else if(cnt<=n){
        printf ("Good Guess!\n");
       }
        break;
        //finish=1;
       }
       if(cnt>n){
        printf ("Game Over\n");
        break;
       }
       
    }
    return 0;
}