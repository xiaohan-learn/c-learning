/*练习：写循环遍历字符数组，逐个打印字符。*/
// #include <stdio.h>

// int main(){
//     char arr[]={'h','e','l','l','o'};
//     int len=sizeof(arr)/sizeof (arr[0]);
//     for(int i=0;i<len;i++){
//         printf("%c ",arr[i]);
//     }
//     return 0;
// }

/*练习：不使用strlen，用指针手写求字符串长度*/
// #include <stdio.h>
// int main(){
//     char *arr="hello world";
//     int cnt=0;
//     while(*arr!='\0'){
//         cnt++;
//         arr++;
//     }
//     printf("字符串长度:%d",cnt);

//     return 0;
// }

/*练习：使用strlen，用指针手写求字符串长度*/
// #include <stdio.h>
// #include <string.h>

// int main(){
//     char *arr="hello world";
//     int len=(int)strlen(arr);
//     printf("字符串长度:%d",len);
//     return 0;
// }

/*练习：结构体数组，循环打印所有学生信息。*/
// #include <stdio.h>
// typedef struct{
//     int id;
//     char name[30];
//     float score;
// }student;

// int main(){
//     student arr[]={
//         {101,"zhang san",89},
//         {102,"li si",78.5},
//         {103,"wang wu",87}
//     };
//     int len=sizeof(arr)/sizeof(arr[0]);
//     printf("----数组循环打印---\n");
//     for(int i=0;i<len;i++){
//         printf("学号:%d 姓名:%s 成绩：%.1f\n",arr[i].id,arr[i].name,arr[i].score);
//     }

//     printf("----指针循环打印---\n");
//     student *p=arr;
//     for(p=arr;p<arr+len;p++){
//          printf("学号:%d 姓名:%s 成绩:%.1f\n",p->id,p->name,p->score);
        
//     }
//     return 0;
// }

/*合并大练习（重点！把三块 + 文件放一起写，一次性复习）
需求：定义学生结构体，把学生信息写入文本文件，再读出来打印。*/
// #include <stdio.h>

// typedef struct{
//     int id;
//     char name[30];
//     float score;
// }student;

// int main(){
//    student arr[]={
//         {101,"zhang san",89},
//         {102,"li si",78.5},
//         {103,"wang wu",87}
//     };

//     FILE *fp=fopen("test.dat","wb");
//     if(fp==NULL){
//         perror("wb fopen error");
//         return 1;
//     }
//     fwrite(arr,sizeof(student),sizeof(arr)/sizeof(student),fp);
//     fclose(fp);
//     fp=NULL;

//     FILE *rp=fopen("test.dat","rb");
//     if(rp==NULL){
//         perror("rb fopen error");
//         return 1;
//     }
//     student s;
//     while((fread(&s,sizeof(student),1,rp))==1){
//         printf("学号:%d 姓名:%s 成绩:%.1f\n",s.id,s.name,s.score);
//     }

//     fclose(rp);
//     rp=NULL;
//     return 0;
// }

/*## 作业 1：字符数组 + 循环
题目：定义字符数组 `char str[] = "C language file io";`
用 while 循环，统计大写字母、小写字母的个数**，最后打印两个计数。
知识点：字符数组遍历，`str[i]` 判断字符范围*/
// #include <stdio.h>

// int main(){
//     char str[]="C language file io";
//     int Acnt=0;
//     int acnt=0;
//     char *p=str;
//     while(*p!='\0'){
//         if(*p>='A' && *p<='Z'){
//             Acnt++;
//         }else if(*p>='a' && *p<='z'){
//             acnt++;
//         }
//         p++;
//     }
//     printf("大写字母个数Acnt=%d,小写字母个数acnt=%d",Acnt,acnt);
//     return 0;
// }

/*作业 2：指针基础练习
题目：运行
int arr[5] = {10,20,30,40,50};
int *p = arr;
用指针 p（不能用下标arr[i]）for 循环打印数组全部 5 个元素。*/
// #include <stdio.h>
// int main(){
//     int arr[5]={10,20,30,40,50};
//     int *p=arr;
//     for(p=arr;p<arr+5;p++){
//         printf("%d ",*p);
//     }
//     return 0;
// }

/*作业 3：指针函数
写函数 void swap2(int *a, int *b, int *c)
功能：交换三个整数，把 a,b,c 的值轮换：原来 a 的值到 b，b 到 c，c 到 a。
main 里面测试：输入 1,2,3，调用函数后输出 3,1,2。*/
// #include <stdio.h>
// void swap2(int *a,int *b,int *c);

// int main(){
//     int a,b,c;
//     printf("请输入三个数字：");
//     scanf ("%d %d %d",&a,&b,&c);
//     printf("交换前：%d %d %d\n",a,b,c);

//     swap2(&a,&b,&c);
//     printf("交换后：%d %d %d\n",a,b,c);
//     return 0;
// }

// void swap2(int *a,int *b,int *c){
//     int tem1=*a;
//     int tem2=*b;
//     *a=*c;
//     *b=tem1;
//     *c=tem2;   
// }

/*作业 4：指针字符串
写函数 int my_strcpy(char *dest, const char *src)
功能：自己实现字符串拷贝（不能用 string.h 库函数 strcpy），把 src 字符串复制到 dest；
返回拷贝的字符数量。
main 测试：src="hello c"，复制到 dest 数组，打印 dest。*/
// #include <stdio.h>
// int my_strcpy(char *dest,const char*src);

// int main(){
//     char src[]="hello.c";
//     char dest[20];
//     int len=my_strcpy(dest,src);
//     printf("拷贝后的字符串:%s\n",dest);
//     printf("拷贝字符数量:%d\n",len);
//     return 0;
// }

// int my_strcpy(char *dest,const char *src){
//     int cnt= 0;
//     while(*src!='\0'){
//         *dest=*src;
//         dest++;
//         src++;
//         cnt++;
//     }
//     *dest='\0';
//     return cnt;
// }

/*作业 5：结构体基础
定义结构体 struct Book，成员：书名 char name [30]，价格 float price。
在 main 函数创建 2 本书的结构体变量，给成员赋值，打印两本书信息*/
// #include <stdio.h>
//  struct book{
//     char name[30];
//     float price;
// };

// int main(){
//    struct book arr[]={
//         {"公共英语",45},
//         {"高等数学",58.5}
//     };
//     for(int i=0;i<2;i++){
//         printf("书名:%s 价格:%.2f元\n",arr[i].name,arr[i].price);
//     }
//     return 0;
// }

/*作业 6：结构体数组循环
struct Book 同上。
创建结构体数组，存放 3 本书信息。使用 for 循环遍历，打印全部书籍；同时计算 3 本书总价。*/
// #include <stdio.h>
// struct book{
//     char name[30];
//     float price;
// };
// int main(){
//     struct book arr[3]={
//          {"公共英语",45},
//          {"高等数学",58.5},
//          {"c语言",50}
//     };
//     float sum=0;
//     for(int i=0;i<3;i++){
//         sum+=arr[i].price;
//         printf("书名:%s 价格:%.2f元\n",arr[i].name,arr[i].price);
//     }
//     printf("三本书总价:%.2f元\n",sum);
//     return 0;
// }

/*作业 7：文本文件综合
struct Book 同上。
在 main 里准备 3 本书信息；
以 w 方式打开 book.txt，循环把 3 本书写入文本文件；
关闭文件；
再以 r 打开 book.txt，循环读取每一本书，在控制台打印；
必须判断 fopen 返回的 FILE 指针是否为空，出错用 perror 提示。*/
// #include <stdio.h>
// typedef struct{
//     char name[30];
//     float price;
// }book;

// int main(){
//     book arr[3]={
//         {"公共英语",45},
//         {"高等数学",58.5},
//         {"c语言",50}
//     };
//     FILE *fp=fopen("book.txt","w");
//     if(fp==NULL){
//         perror("w fopen error");
//         return 1;
//     }
//     for(int i=0;i<3;i++){
//     fprintf(fp,"%s %.2f\n",arr[i].name,arr[i].price);
//     }

//     fclose(fp);
//     fp=NULL;

//     FILE *rp=fopen("book.txt","r");
//     if(rp==NULL){
//         perror("r fopen error");
//         return 1;
//     }
//     printf("从文件中读取数据:\n");
//     for(int a=0;a<3;a++){
//         fscanf(rp,"%s %f ",arr[a].name,&arr[a].price);
//         printf("书名:%s 价格:%.2f\n",arr[a].name,arr[a].price);
//     }

//     fclose(rp);
//     rp=NULL;
//     return 0;
// }

/*作业 8：二进制文件综合（难点）
struct Book 同上。结构体数组存放 2 本书；
wb 模式打开 book.bin，fwrite 一次性写入 2 本书；fclose；
rb 模式打开 book.bin，fread 读取 2 本书到新的结构体数组；
控制台打印读取出来的书籍名称和价格。*/
// #include <stdio.h>
// typedef struct {
//     char name[30];
//     float price;
// }book;

// int main(){
//     book arr[2]={
//         {"公共英语",45},
//         {"高等数学",56.5}
//     };

//     FILE *fp=fopen("book.bin","wb");
//     if(fp==NULL){
//         perror("wb fopen error");
//         return 1;
//     }
//     fwrite(arr,sizeof(book),2,fp);
//     fclose(fp);
//     fp=NULL;

//     FILE *rp=fopen("book.bin","rb");
//     if(rp==NULL){
//         perror("rb fopen error");
//         return 1;
//     }
//     book s;
//     for(int i=0;i<2;i++){
//         if(fread(&s,sizeof(book),1,rp)==1){
//         printf("%s %.2f\n",s.name,s.price);
//       }
//     }
//     fclose(rp);
//     rp=NULL;
//     return 0; 
// }

/*作业9
定义学生结构体（id、name、score），malloc 动态申请 3 个学生内存，赋值、打印，最后 free。*/
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// typedef struct{
//     int id;
//     char name[30];
//     float score;
// }stu;

// int main(){
//     stu *p=(stu *)malloc(3*sizeof(stu));
//     if(p==NULL){
//         perror("内存分配失败");
//         return 1;
//     }
//     //方法一：加类型名
//     // p[0]=(stu){101,"zhang san",78};
//     // p[1]=(stu){102,"li si",85.5};
//     // p[2]=(stu){103,"wang wu",84};

//     //方法二：逐个给成员赋值
//     // p[0].id=101;
//     // strcpy(p[0].name,"zhang san");
//     // p[0].score=78;
//     // p[1].id=102;
//     // strcpy(p[1].name,"li si");
//     // p[1].score=85.5;
//     // p[2].id=103;
//     // strcpy(p[2].name,"wang wu");
//     // p[2].score=84;

//     //方法三：整体拷贝临时结构变量
//     stu tem1={101,"zhang san",78};
//     stu tem2={102,"li si",85.5};
//     stu tem3=(stu){103,"wang wu",84};
//     p[0]=tem1;
//     p[1]=tem2;
//     p[2]=tem3;

//     for(int i=0;i<3;i++){
//         printf("%d %s %.2f\n",p[i].id,p[i].name,p[i].score);
//     }

//     free(p);
//     p=NULL;
//     return 0;
// }

/*作业 10（realloc 动态扩容，核心！）
struct Book 同上。
需求：初始只开 1 个 book 空间，循环追加，每次不够就扩容 + 1。*/
// #include <stdio.h>
// #include <stdlib.h>
// struct book{
//     char name[30];
//     float price;
// };

// int main(){
//     int cnt=0;
//     int cap=1;//当前容量
//     struct book *p=(struct book *)malloc((size_t)cap*sizeof(struct book));
//     if(p==NULL){
//         perror("p 内存分配失败");
//         return 1;
//     }
//     p[cnt++]=(struct book){"高等数学",56.5};

//     if(cnt>=cap){
//         cap++;
//         struct book *tem=(struct book *)realloc(p,(size_t)cap*sizeof(struct book));
//         if(tem==NULL){
//             perror("realloc 内存分配失败");
//             free(p);
//             return 1;
//         }
//         p=tem;
//     }
//     p[cnt++]=(struct book){"公共英语",45};

//     for(int i=0;i<cnt;i++){
//         printf("%s %.2f\n",p[i].name,p[i].price);
//     }

//     free(p);
//     p=NULL;
//     return 0;
// }

/*作业 11【综合大题：文件 + 动态内存，面试题】
需求：
1. 先写 3 本书到 book2.bin 二进制文件
2. 再打开 book2.bin，**不知道文件里面有多少条记录**，循环 fread 读取，动态扩容内存保存所有书籍
3. 读取完成，循环打印全部书籍
4. 释放堆内存，关闭文件*/
// #include <stdio.h>
// #include <stdlib.h>
// typedef struct{
//     char name[30];
//     float price;
// }book;

// int main(){
//     book arr[]={
//         {"公共英语",45},
//         {"高等数学",58.5},
//         {"c语言",50}
//     };
//     FILE *fp=fopen("book2.bin","wb");
//     if(fp==NULL){
//         perror("wb fopen error");
//         return 1;
//     }
//     fwrite(arr,sizeof(book),3,fp);
//     fclose(fp);
//     fp=NULL;

//     FILE *rp=fopen("book2.bin","rb");
//     if(rp==NULL){
//         perror("rb fopen error");
//         return 1;
//     }
    
//     int cnt=0;
//     int cap=1;
//     book tem;
//     book *list=(book *)malloc((size_t)cap*sizeof(book));
//     if(list==NULL){
//         perror("内存分配失败");
//         return 1;
//     }

//     while(fread(&tem,sizeof(book),1,rp)==1){
//         if(cnt>=cap){
//             cap*=2;
//             book *tem_str=(book *)realloc(list,(size_t)cap*sizeof(book));
//             if(tem_str==NULL){
//                 perror("realloc error");
//                 free(list);
//                 return 1;
//             }
//             list=tem_str;
//         }
//         list[cnt++]=tem;  
//     }

//      for(int i=0;i<cnt;i++){
//             printf("%s %.2f\n",list[i].name,list[i].price);
//         }

//     fclose(rp);
//     rp=NULL;
//     free(list);
//     list=NULL;
    
//     return 0;   
// }

/*作业12（进阶）
写一个函数：`int read_all_student(const char *filename, student **out, int *total)`
功能：读取二进制文件，动态分配内存，学生数组地址放到 out，
总条数放到 total；返回 0 成功，-1 失败。*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[30];
    float score;
}stu;

int read_all_student(const char *filename,stu **out,int *total){
    if(out==NULL || total==NULL || filename==NULL){
        return -1;
    }
    *out=NULL;
    *total=0;

    FILE *fp=fopen(filename,"rb");
    if(fp==NULL){
        perror("rb fopen error");
        return -1;
    }
    int cap=1;
    int cnt=0;
    stu tem;
    stu *p=(stu *)malloc((size_t)cap*sizeof(stu));
    if(p==NULL){
        perror("malloc error");
        fclose(fp);
        return -1;
    }

    while(fread(&tem,sizeof(stu),1,fp)){
        if(cnt>=cap){
            cap*=2;
            stu *tem_str=(stu *)realloc(p,(size_t)cap*sizeof(stu));
            if(tem_str==NULL){
                perror("realloc error");
                fclose(fp);
                free(p);
                return -1;
            }
            p=tem_str;
        }
        p[cnt++]=tem;
    }

    *out=p;
    *total=cnt;

    fclose(fp);
    fp=NULL;

    return 0;
}

int main(){
    stu arr[]={
        {101,"zhang san",89.5},
        {102,"li si",78.5},
        {103,"wang wu",95}
    };
    FILE *fp=fopen("stu.bin","wb");
    if(fp==NULL){
        perror("wb fopen error");
        return -1;
    }
    fwrite(arr,sizeof(stu),3,fp);
    fclose(fp);
    fp=NULL;

    int num;
    stu *list=NULL;
    int ret=read_all_student("stu.bin",&list,&num);
    if(ret==0){
        printf("读取成功,总共有%d个学生\n",num);
        for(int i=0;i<num;i++){
            printf("%d %s %.2f\n",list[i].id,list[i].name,list[i].score);
        }
    }else {
        printf("读取失败\n");
    }

    free(list);
    list=NULL;
    return 0;

}