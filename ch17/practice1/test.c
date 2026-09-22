/*（头插建表 + 遍历）​：读入 n，循环 n 次用头插法建表，
然后遍历打印。验证"头插 = 逆序"（你输入 1 2 3，打印出来 3 2 1）。
- 定义节点结构 `Node`（data = int，next 指向下一个节点）。
- main 里：读入 `n`，循环 `n` 次，每次读一个整数 `x`，用**头插法**插入链表。
- 建完后遍历打印全部节点。*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *creatnode(int val){
    Node *newnode=(Node*)malloc(sizeof(Node));
    if(newnode==NULL){
        perror("创建空间失败");
        return NULL;
    }
    newnode->data=val;
    newnode->next=NULL;
    return newnode;
}

void head_insert(Node**head,int n){
    Node *newnode=creatnode(n);
    newnode->data=n;
    newnode->next=*head;
    *head=newnode;
}

void print_list(Node*head){
    Node*p=head;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}
 
int main(){
    Node *head=NULL;
    int n,x;
    printf("请输入n:");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("请输入第%d个数字:",i+1);
        scanf("%d",&x);
        head_insert(&head,x);
    }

    printf("遍历结果");
    print_list(head);
    return 0;

}

