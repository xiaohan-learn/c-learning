/*★1. 手写字符串拷贝 my_strcpy（返回目标串首地址）
- 盲写：`char* my_strcpy(char* dest, const char* src)`，
不用库函数，把 src 拷到 dest，返回 dest。
- 验收：`my_strcpy(b,a)` 后 `b` 内容与 `a` 一致；返回值是 `b` 的首地址。
- 回看：BUG.md #1（返回类型必须是 `char*`）;旧代码ch12/practice2/my_strcpy.c*/
// #include <stdio.h>
// char *my_strcpy(char *dest,const char *src){
//     char *ret=dest;
//      while(*src!='\0'){
//         *dest=*src;
//         dest++;
//         src++;
//      }
//      *dest='\0';
//      return ret;
// }
// int main(){
//     const char *a="hello world";
//     char b[50];
//     char *p=my_strcpy(b,a);
//     printf("拷贝后的b为%s\n",b);
//     printf("b的首地址为%p\n",p);
//     return 0;
// }

/*★2. 手写字符串比较 my_strcmp
- 盲写：`int my_strcmp(const char* s1, const char* s2)`，
逐字符比，返回首对差异字符的 ASCII 差值（相等返 0）。
- 验收："abc"` vs `"abd"`返负值；`"ab"` vs `"abc"` 返负值；相同返 0。
- 回看：BUG.md #2（形参 `char*`不是`char*[]`；用`&&`不是`&`；返回差值不是 0/1）；
`ch12/practice3/my_strcmp.c`*/
// #include <stdio.h>
// int my_strcmp(const char *s1,const char *s2){
//     while(*s1!='\0' && *s2!='\0' && *s1==*s2 ){
//         s1++;
//         s2++;
//     }
//     return *s1-*s2;
// }

// int main(){
//     const char *a="abc";
//     const char *b="ab";
//     int ret=my_strcmp(b,a);
//     if(ret==0){
//         printf("俩字符串相等\n");
//     }else{
//         printf("俩字符串不同\n");
//     }
//     return 0;
// }

/*★3. 位运算四件套：置/清/翻/取第 n 位
- 盲写：用 `num` 和第 n 位（n 从 0 起）写出 ①置位 ②清位 ③翻转 ④取该位值 四行。
- 验收：设 `num=0b1010`，清第 1 位后应得 `0b1000`；取第 3 位得 1。
- 回看：BUG.md #7（清位必须&= ~(1u<<n)，漏 `~` 就错）；ch14/practice1/bits.c*/
// #include <stdio.h>
// void printbin(unsigned int num,int len){
//     printf("0b");
//     for(int i=len-1;i>=0;i--){
//         if(num &(1u<<i)){
//             printf("1");
//         }else{
//             printf("0");
//         }
//     }
// }
// int main(){
//     unsigned int num=0b1010;
//     //置位
//     num |=(1u<<2);
//     printf("置第二位后=");
//     printbin(num,4);
//     printf("(预期为0b1110)\n");

//     //清位
//     unsigned int num1=0b1010;
//     num1 &=~(1u<<1);
//     printf("清第一位后=");
//     printbin(num1,4);
//     printf("(预期为0b1000)\n");

//     //翻转
//     unsigned int num2=0b1010;
//     num2 ^=(1u<<3);
//     printf("翻转第三位后=");
//     printbin(num2,4);
//     printf("(预期为0b0010)\n");

//     //取位
//     unsigned int num3=0b1010;
//     int ret=(num3>>1)&1;
//     printf("取第一位值为%d(预期为1)\n",ret);

//     return 0;
// }

/*★4. 带参宏：SQR 与 MAX
盲写：写出两个宏
① 求平方 #define SQR(x) ...
② 求两值较大者 #define MAX(a, b) ...
要求正确（带参宏的“三对括号”规则：宏体整体一对括号、每个参数各一对括号）。
验收：SQR(5) 得 25；MAX(3, 7) 得 7；并且你能说清为什么 SQR(++i) 是错的（未定义行为）​。
回看：BUG.md #13（带参宏三括号 + 副作用 UB）；
旧代码 ch16/practice1/test.c（里面就有写错的 SQR 版本）。*/

// #include <stdio.h>
// #define SQR(x) ((x)*(x))
// #define MAX(a,b) ((a>b)?(a):(b))

// int main(){
//     int a=SQR(5);
//     int ret=MAX(3,7);
//     printf("a=%d\n",a);
//     printf("ret=%d\n",ret);
//     return 0;
// }

/*★5 盲写任务：状态机（State Machine）
盲写：用 enum 定义一组状态，写一个循环 + switch 的状态机。
给你两个任选其一（建议挑交通灯，最直观）：
A. 交通灯：状态 RED → GREEN → YELLOW → RED 无限循环，每轮打印当前灯并打印“下一盏是什么”。
B. 字符分类器：读一个字符串，用状态机思路统计 字母 / 数字 / 空格 的个数（遇到 \0 结束）。
关键点：一个 state 变量 + 在 switch 的每个分支里更新 state 完成转移。
验收：状态能正确流转、不会卡死（死循环但永远同一状态）、不会越界；
用 enum 而不是裸数字；switch 有 default。
回看：BUG.md 里状态机那条（典型坑：① 转移时忘了改 state，导致永远停在一个状态；
② case 漏 break 导致穿透 fall-through；③ 用 1/2/3 魔法数字代替 enum）；
旧代码 ch19/practice6/student.c（菜单+枚举+存档 就是个状态机雏形）。*/
//  A:交通灯
// #include <stdio.h>
// #include <windows.h> // Windows平台。Linux换成 #include <unistd.h>
// enum light{
//     RED,GREEN,YELLOW
// };

// int main(){
//    enum light state=RED;
//    int round=0;
//    while(round<6){
//     switch(state){
//         case RED: printf("当前灯为红灯\t");
//         printf("下一盏：绿灯\n");
//         Sleep(3000);//5000ms=5s
//         state=GREEN;
//         break;

//         case GREEN: printf("当前灯为绿灯\t");
//         printf("下一盏：黄灯\n");
//         Sleep(2000);
//         state=YELLOW;
//         break;

//         case YELLOW: printf("当前灯为黄灯\t");
//         printf("下一盏：红灯\n");
//         Sleep(1000);
//         state=RED;

//         break;
//         default : printf("异常状态，复位到红灯\n");
//         Sleep(1000);
//         state=RED;
//         break ;
//     }
//     round++;
//    }
//    return 0;
// }

// B：字符分类器
// #include <stdio.h>
// enum charlist{
//     START,READING,END
// };

// int main(){
//     char arr[]="Hello 1 2 3 World";
//     int i=0;
//     int cnt_letter=0;
//     int cnt_digit=0;
//     int cnt_space=0;
//     enum charlist state=START;
//     while(1){
//         switch(state){
//             case START: state=READING;
//             break;

//             case READING:{
//                char ch=arr[i];
//                if(ch=='\0'){
//                 state=END;
//                 break;
//                } 
//                if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
//                 cnt_letter++;
//                }else if(ch>='0' && ch<='9'){
//                 cnt_digit++;
//                }else if(ch==' '){
//                 cnt_space++;
//                }
//                i++;
//                state=READING;
//                break;
//             }

//             case END:
//             printf("字母:%d\n数字:%d\n空格:%d\n",cnt_letter,cnt_digit,cnt_space);
//             return 0;

//             default:printf("状态异常:复位为START\n");
//             state=START;
//             break;
//         }
//     }
//     return 0;
// }

/*★6. 链表尾插找尾：循环条件
- 盲写：写 `tail_insert(Node** head, int n)` 把新节点接到链表末尾
（注意空表分支 + 找尾循环条件）。
- 验收：输入 1 2 3 尾插，遍历打印 `1 2 3`；非空表不崩。
- 回看：BUG.md #17（找尾用 `while(p->next!=NULL)`，用 `p!=NULL` 会段错误）；
`ch18/practice4/insert.c`*/
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct Node{
//     int data;
//     struct Node *next;
// }Node;

// Node *creatnode(int n){
//     Node *newnode=(Node *)malloc(sizeof(Node));
//     if(newnode==NULL){
//         perror("malloc error");
//         return NULL;
//     }
//     newnode->data=n;
//     newnode->next=NULL;
//     return newnode;
// }

// void tail_insert(Node **head,int n){
//     Node *newnode=creatnode(n);
//     if(*head==NULL){
//         newnode->next=NULL;
//         *head=newnode;
//         return ;
//     }
//     Node *p=*head;
//     while(p->next!=NULL){
//         p=p->next;
//     }
//     p->next=newnode;
//     newnode->next=NULL;
// }

// void print_list(Node *head){
//     Node *p=head;
//     while(p!=NULL){
//         printf("%d\n",p->data);
//         p=p->next;
//     }
// }

// void free_list(Node *head){
//     Node *p=head;
//     while(p!=NULL){
//         Node *tem=p;
//         p=p->next;
//         free(tem);
//     }
// }

// int main(){
//     Node *head=NULL;
//     tail_insert(&head,1);
//     tail_insert(&head,2);
//     tail_insert(&head,3);
//     print_list(head);

//     free_list(head);
//     head=NULL;
//     return 0;
// }

/*★7. 综合项目 add() 必须入库
- 盲写：写一个「添加学生到全局数组」的函数片段，填好结构体后必须让数组真正多出一条。
- 验收：函数末尾有 `stulist[stucount]=s; stucount++;`（或等价），否则列表始终空。
- 回看：BUG.md #20（**填完结构体别忘了入库那两行，否则保存是空文件**）；
`ch19/practice6/student.c`*/
#include <stdio.h>
#include <string.h>

typedef struct{
    int id;
    char name[30];
    float score;
}stu;

#define MAX_STU 100
stu stulist[MAX_STU];
int stucnt=0;

void input_str(char *buf,int len){
    if(fgets(buf,len,stdin)==NULL){
        buf[0]='\0';
        return ;
    }
    buf[strcspn(buf,"\n")]='\0';
}

void add(){
    stu s;
    if(stucnt>=MAX_STU){
        printf("人数已满\n");
        return;
    }
    printf("----添加学生信息----\n");
    printf("请输入 id 姓名 成绩\n");
    char line[100];
    input_str(line,sizeof(line));

    int ret=(sscanf(line,"%d %29s %f",&s.id,s.name,&s.score));
    if(ret!=3){
        printf("输入格式错误\n");
        return;
    }
    stulist[stucnt++]=s;
    printf("添加成功！当前人数%d\n",stucnt); 
}

int main(){
    add(); add(); add();
    for(int i=0;i<3;i++){
        printf("%d %s %.1f\n",stulist[i].id,stulist[i].name,stulist[i].score);
    }
    return 0;
}