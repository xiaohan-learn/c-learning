/*把链表和今天的"结构体"串一下——节点存 int score 而不是单值，体会"节点就是结构体"。
- 节点 data 换成 `int score`（或 `struct Student { int id; int score; }` 里挑一个字段），
体会节点就是结构体，头插/遍历/释放照旧。*/
#include <stdio.h>
#include <stdlib.h>

typedef struct student{
    int id;
    int score;
}stu;

typedef struct Node{
    stu data;
    struct Node *next;
}Node;

Node *creatnode(int id,int score){
    Node *newnode=(Node *)malloc(sizeof(Node));
    if(newnode==NULL){
        printf("创建空间失败");
        return NULL;
    }
    newnode->data.id=id;
    newnode->data.score=score;
    newnode->next=NULL;
    return newnode;
}

void head_insert(Node **head,int id,int score){
    Node *newnode=creatnode(id,score);
        newnode->next=*head;
        *head=newnode;
}


void print_list(Node *head){
    Node *p=head;
    while(p!=NULL){
        printf("学号：%d ,成绩：%d\n",p->data.id,p->data.score);
        p=p->next;
    }
}

void free_list(Node*head){
    Node*p=head;
    while(p!=NULL){
        Node *temp=p;
        p=p->next;
        free(temp);
    }
}

int main (){
    Node *head=NULL;
    int n,id,score;
    printf("请输入n:");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("请输入第%d个学生信息",i+1);
        scanf("%d %d",&id,&score);
        head_insert(&head,id,score);
    }
    printf("遍历结果\n");
    print_list(head);

    free_list(head);
    head=NULL;

    return 0;

}


