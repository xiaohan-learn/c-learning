#include <stdio.h>
int main()
{
    float a=3.14F;  printf ("%f\n",a);
    double b=3.14;  printf ("%.2f\n",b);
    float c=3.15F;  printf ("%.5f\n",c);
    long double d=3.14L;  printf ("%.2Lf\n",d);


    printf("%zu ",sizeof(float));  printf("%zu\n",sizeof(a));
    printf("%zu ",sizeof(double));  printf("%zu\n",sizeof(b));
    printf("%zu ",sizeof(long double));  printf("%zu\n",sizeof(d));
    
    double x=3.1415926;
    printf("%e\n", 1234.56);
    printf("%.3f", x);    printf("%6.2f", x);//6位宽含两位小数

    //小数的数据类型无法跟unsigned使用
}   //unsigned double e=3.14;  printf ("%.21f\n",e);