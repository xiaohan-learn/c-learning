/*1. 拿大数对小数取余数 a % b
  2. 把 b 变成新 a,余数变成新 b
  3. 重复，直到b = 0,计算结束，a是最大公约数
  a   b   t
  12  18  12
  18  12  6
  12  6   0
  6   0     */
  #include <stdio.h>
  int main(void)
  {
    int a=0,b=0;
    scanf ("%d %d",&a,&b);
    int i;
    while(b!=0){
        i=a%b;
        a=b;
        b=i;
        printf ("a=%d,b=%d,c=%d\n",a,b,i);
    }
    printf ("最大公约数是%d\n",a);
    return 0;
  }