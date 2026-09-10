#include <stdio.h>
int main()
{
    short a=1;  printf("%d\n",a);
    int b=10;  printf("%d\n",b);
    long c=100L;  printf("%ld\n",c);
    long long d=1000LL; printf("%lld\n",d);


    printf("%zu ",sizeof(short));  printf("%zu\n",sizeof(a));
    printf("%zu ",sizeof(int));  printf("%zu\n",sizeof(b));
    printf("%zu ",sizeof(long));  printf("%zu\n",sizeof(c));
    printf("%zu ",sizeof(long long));  printf("%zu\n",sizeof(d));

}