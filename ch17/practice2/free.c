/*在练习1 基础上加一个 free_list(head)，遍历释放每个节点；
用 VS 的"诊断工具/内存快照"或打印验证无泄漏（进阶可省）。
- 在练习1 基础上加 `free_list(Node* head)`，按上面「先存 next 再 free」释放所有节点。
- 释放后 `head = NULL`。*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *creatnode(int n){
    Node *newnode=(Node *)malloc(sizeof(Node));
    if(newnode==NULL){
        printf("创建空间失败");
        return NULL;
    }
    newnode->data=n;
    newnode->next=NULL;
    return newnode;
}

void head_insert(Node **head,int n){
    Node *newnode=creatnode(n);
    newnode->next=*head;
    *head=newnode;
}

void print_list(Node*head){
    Node *p=head;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}
 
void free_list(Node *head){
    Node *p=head;
    while(p!=NULL){
        Node *temp=p;
        p=p->next;
        free(temp);
    }
}

int main(){
    Node *head=NULL;
    int n,x;
    printf("请输入n:");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("请输入第%d个数:",i+1);
        scanf("%d",&x);
        head_insert(&head,x);
    }

    printf("遍历结果");
    print_list(head);

    free_list(head);
    head=NULL;

    return 0;
}
