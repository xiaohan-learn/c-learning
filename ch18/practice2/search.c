/*练习2（按值查找）—— 必做
写什么
- `Node* find(Node* head, int val)`：找到返回该节点指针，找不到返回 `NULL`；或返回第几个（下标）。
验收输出
- 头插 1 2 3（表 3 2 1），`find(head, 2)` 应找到（非 NULL）。
坑预警
- 条件 `while(p && p->data != val)`，找到即 `return p`；循环结束 return NULL。*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *creatnode(int val){
    Node *newnode=(Node *)malloc(sizeof(Node));
    if(newnode==NULL){
        printf("内存分配失败");
        return NULL;
    }
    newnode->data=val;
    newnode->next=NULL;
    return newnode;
}

void head_insert(Node **head,int n){
    Node *newnode=creatnode(n);
    newnode->next=*head;
    *head=newnode;
}

void tail_insert(Node **head,int n){
    Node *newnode=creatnode(n);
    if(*head==NULL){
        newnode->next=NULL;
        *head=newnode;
        return;
    }
    Node *p=*head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=newnode;
}

Node *find_node(Node *head,int n){
    Node *p=head;
    while(p!=NULL && p->data!=n){
        p=p->next;
    }
    return p;
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

    head_insert(&head,1);
    head_insert(&head,2);
    head_insert(&head,3);
    tail_insert(&head,4);

    printf("遍历结果\n");
    print_list(head);

    printf("\n");
    
    Node *find=find_node(head,2);
    if(find!=NULL){
        printf("找到了,节点数据=%d\n",find->data);
    }else{
        printf("未找到");
    }

    return 0;
}