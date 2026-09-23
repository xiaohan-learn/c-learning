/*练习4（指定位置插入）—— 必做，重点
写什么
- `void insert_at(Node** head, int pos, int val)`：在第 pos 个位置插入（pos 从 0 起：0=插到表头，1=插到原第 0 个之后…）。
- pos==0 等同头插；pos>0 遍历走到 pos-1 的前驱，新节点 next 接前驱 next，前驱 next 接新节点。
验收输出
- 表 3 2 1，在 pos=1 插 9 → 表变为 3 9 2 1（逆序视角下插在 3 之后）。
- pos=0 插 9 → 9 3 2 1（新头）。
坑预警
- pos 越界（>长度）要处理：要么追加到表尾，要么忽略并提示，别让 `p->next` 踩 NULL。
- pos==0 走头插分支，不能进「找前驱」循环（前驱不存在）。*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *creatnode(int n){
    Node *newnode=(Node *)malloc(sizeof(Node));
    if(newnode==NULL){
        printf("内存分配失败");
        return NULL;
    }
    newnode->data=n;
    newnode->next=NULL;
    return newnode;
}
//尾插
void tail_insert(Node **head,int n){
    Node *newnode=creatnode(n);
    if(*head==NULL){
        *head=newnode;
        return;
    }
    Node *p=*head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=newnode;
    newnode->next=NULL;
}
//指定位置插入
void insert(Node **head,int pos,int n){
    Node *newnode=creatnode(n);
    if(pos==0){
        newnode->next=*head;
        *head=newnode;
        return;
    }
    Node *prev=*head;
    for(int i=0;prev!=NULL && i<pos-1;i++){
        prev=prev->next;
    }
    if(prev==NULL){
        printf("超出链表长度");
        return ;
    }
    newnode->next=prev->next;
    prev->next=newnode;
}

void print_list(Node *head){
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

    tail_insert(&head,3);
    tail_insert(&head,2);
    tail_insert(&head,1);
    printf("指定位置插入前遍历结果：");
    print_list(head);

    printf("\n");

    insert(&head,1,9);
    printf("指定位置插入后遍历结果:");
    print_list(head);

    free_list(head);
    head=NULL;

    return 0;

}