//静态链表

#include <stdio.h>
typedef struct Node{
    int num;
    struct Node*next;
}Node;

int main(){
    Node a,b,c,*head;
    a.num=2;
    b.num=3;
    c.num=4;

    head=&a;
    a.next=&b;
    b.next=&c;
    c.next=NULL;

    Node *p=head;
    do{
        printf("%d ",p->num);
        p=p->next;
    }while(p!=NULL);
    return 0;

}