/*让用户输入一个整数 n（表示初始元素个数），用 malloc 动态申请 n 个 int 的空间。
依次读入 n 个整数存入数组，并打印出来。
再让用户输入一个整数 m，用 realloc 把数组扩大到 n + m 个元素。
读入新增的 m 个整数，打印扩容后的全部 n + m 个元素。
最后正确释放内存。
要求
每一步分配后都要检查是否为 NULL
realloc 必须用临时指针接收
free 后把指针置为 NULL*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    int* p=(int*)malloc ((size_t)n*sizeof(int));
    if(p==NULL){
        perror("申请空间失败");
        return 1;
    }
    int i=0;
    for(i=0;i<n;i++){
        p[i]=i+2;
        printf("%d ",p[i]);
    }
    int m;
    scanf("%d",&m);
    int*ptr=(int*)realloc(p,(size_t)(n+m)*sizeof(int));
    if(ptr==NULL){
        perror("realloc申请空间失败");
        free(p);
        p=NULL;
        return 1;
    }else
    {
        p=ptr;
        ptr=NULL;
    }
    for(i=n;i<n+m;i++){
        p[i]=i*10;
        printf("%d ",p[i]);
    }
    printf("\n");
    for(i=0;i<m+n;i++){
        printf("%d ",p[i]);
    }
    free(p);
    p=NULL;
    return 0;
}