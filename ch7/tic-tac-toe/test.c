#include <stdio.h>
int main()
{
    const int size=3;
    int board[size][size];
    int numx,numo;
    int result=-1;//-1暂时没人赢，1代表x赢，0代表o赢；
    int i,j;
    for(i=0;i<size;i++){    // 输入棋盘
        for(j=0;j<size;j++){
            scanf("%d",&board[i][j]);}
        }
        //检查行
        for(i=0;i<size && result==-1;i++){
            numo=numx=0; //每开始统计新一行时，把 X 和 O 的计数清零。
            for(j=0;j<size;j++){   //遍历当前行的每一列
                if(board[i][j]==1){
                    numx++;
                }else numo++;
            }
         if(numx==size){
            result=1;
        }else if(numo==size) result=0;}
        //检查列
       for(j=0;j<size&&result==-1;j++){
            numo=numx=0;
            for(i=0;i<size;i++){
                if(board[i][j]==1){
                    numx++;
                }else numo++;
            }
        if(numx==size){
            result=1;
        }else if(numo==size) result=0; }
        //检查对角线1：左上→右下
        numo=numx=0;
        for(i=0;i<size&&result==-1;i++){
            if(board[i][i]==1){   //i既是行号也是列号：board[i][i]→ (0,0),(1,1),(2,2)
                numx++;
            }else numo++;
        }
         if(numx==size){
            result=1;
        }else if(numo==size) result=0;
        //检查对角线2：右上→左下
        numo=numx=0;
       for(i=0;i<size&&result==-1;i++){
            if(board[i][size-i-1]==1){  //对应坐标：(0,2),(1,1),(2,0)
                numx++;
            }else numo++; 
        }
        if(numx==size){
            result=1;
        }else if(numo==size) result=0;

        //输出结果
        if(result==1){
            printf("x赢了\n");
        }else if(result==0){
            printf("o赢了\n");
        }else printf("没人赢\n");
    return 0;
}