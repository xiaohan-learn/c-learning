/*练习3（删除指定值结点）—— 必做，重点
写什么
- `void delete_val(Node** head, int val)`：删除第一个值为 val 的结点，释放其内存。
- 分两种情况：删的是头结点（head 要指向 head->next）；删的是中间结点（前驱的 next 跳过它）。
验收输出
- 表 3 2 1，删 2 → 打印 3 1；删 3（头）→ 打印 2 1；删不存在的 9 → 表不变。
坑预警（最易错）
- 删头结点：用双指针 `*head = (*head)->next;` 再 free 原头，否则 head 还指向已释放内存。
- free 顺序：先 `Node* t = p->next`（存后继）→ `free(p)` → 前驱 `prev->next = t`，绝不能 free 后再读 p->next。
- 遍历要保留「前驱指针 prev」，删中间结点靠 prev->next 跳过。*/
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

void head_insert(Node **head,int n){
    Node *newnode=creatnode(n);
    newnode->next=*head;
    *head=newnode;
}

void tail_insert(Node **head,int n){
    Node *newnode=creatnode(n);
    if(*head==NULL){
        *head=newnode;
        return;
    }
    Node *p=*head;
    while(p->next!=NULL ){
        p=p->next;
    }
    p->next=newnode;
    newnode->next=NULL;
}

void delnode(Node **head,int n){
    if(*head==NULL){
        return;
    }
    //删除头结点
    if((*head)->data==n){
        Node *temp=*head;
        *head=(*head)->next;
        free(temp);
        return ;
    }
    //删除中间结点
    Node *prev=*head;
    while(prev->next!=NULL && prev->next->data!=n){
        prev=prev->next;
    }
    if(prev->next!=NULL){
    Node *temp=prev->next;
    prev->next=temp->next;
    free(temp);
    }
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

    printf("删除前遍历结果：");
    print_list(head);

    printf("\n");

    delnode(&head,2);
    printf("删除后遍历结果：");
    print_list(head);

    free_list(head);
    head=NULL;


    return 0;

}

