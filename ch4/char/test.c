#include <stdio.h>
int main()
{
    char a1='B';
    printf ("%d ",a1);  printf("'%c'\n",a1);
    char C=49;
    printf ("%d ",C);  printf("'%c'\n",C);
    
    //字符加减
    char b1='1';
    printf("%d\n",a1-b1);

    //有无空格
    int i; char k;  scanf("%d %c",&i,&k);
    printf("i=%d,k=%d,k='%c'\n",i,k,k);
    int m; char n;  scanf("%d%c",&m,&n);
    printf("m=%d,n=%d,n='%c'\n",m,n,n);

    //大小写转换
    char p='D';  char lower=p-'A'+'a';
    printf("大写 %c 转小写：%c\n", p, lower);
    char q='d';  char upper=q-'a'+'A';
    printf("小写 %c 转大写：%c\n", q, upper);
  
    return 0;
}