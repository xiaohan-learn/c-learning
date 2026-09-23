/*练习1（求长度）—— 必做，最简单
写什么
- int length_list(Node* head)：遍历计数返回节点数。
验收输出
- 建表输入 1 2 3（头插后实际 3 2 1），`length_list` 返回 3。
坑预警
- 空表 `head==NULL` 返回 0，别越界。*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *creatnode (int n){
    Node *newnode=(Node*)malloc(sizeof(Node));
    if(newnode==NULL){
        printf("申请空间失败");
        return NULL;
    }
    newnode->data=n;
    newnode->next=NULL;
    return newnode;
}

void headnode(Node**head,int n){
    Node *newnode=creatnode(n);
    newnode->next=*head;
    *head=newnode;
}

int length_list(Node *head){
    Node *p=head;
    int count=0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
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
   int num,x;
    printf("请输入num:");
    scanf("%d",&num);

    for(int i=0;i<num;i++){
        printf("请输入第%d个数字:",i+1);
        scanf("%d",&x);
        headnode(&head,x);
    }
     
    int len=length_list(head);
    printf("长度为%d\n",len);

    free_list(head);
    head=NULL;
    
    return 0;
}