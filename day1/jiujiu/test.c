 #include <stdio.h>
 int main (void)
 {
    int n=0;
    scanf ("%d",&n);
    int i,j;
    for (i=1;i<=n;i++){
        for (j=1;j<=i;j++){
            printf ("%d*%d=%-4d",j,i,i*j);
           
        }printf ("\n");
    } 
    return 0;
 }