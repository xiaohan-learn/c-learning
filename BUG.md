# C 语言易错点清单（BUG.md）

> 用途：每周六复盘时翻一遍，比重读整章高效 10 倍。每条都是小涵亲手踩过的坑。
> 维护规则：每发现一个 bug 就补一条，格式固定为「现象 / 原因 / 正确写法 / 口诀」。
> 状态标记：[偶尔忘] = 还会犯，优先回刷；[已掌握] = 已基本固化。

---

## 怎么用这个文件（呼应"遗忘对抗方案②"）
1. 周六盲写旧章练习**前**，先扫对应章节条目，给自己提个醒。
2. 回刷时发现又犯了某条，把标记从 [已掌握] 改回 [偶尔忘]。
3. 新 bug 随时追加在对应章节末尾，编号顺延。

---

## 通用铁律（横跨所有章节）
- 自定义类型（`struct`/`enum`/`typedef`）一律写在文件**最前面**，先定义后使用。
- 凡是要返回字符串或地址的函数，返回类型必须是 `char*`，不是 `char`。
- 逻辑与是 `&&`、按位是 `&`；别混。
- 指针遍历三件套：初值、条件、**前进（`p++`）**，漏了前进就死循环。

---

## ch12 字符串

### 1. my_strcpy 返回类型写错  [偶尔忘]
- 现象：函数返回 `char`，却 `return` 字符串首地址，编译警告/类型不匹配。
- 原因：字符串函数语义是"返回目标串首地址"，返回类型必须是 `char*`。
- 正确：`char* my_strcpy(char* dest, const char* src)`
- 口诀：要返回字符串/地址 → 返回类型就是 `char*`。

### 2. my_strcmp 形参与比较运算符  [偶尔忘]
- 现象：形参写成 `char* str1[]`（数组的数组）；用 `&` 代替 `&&`；返回写成 `str1 - str2`。
- 原因：形参应是 `char*` 而非 `char*[]`；逻辑与是 `&&`；strcmp 返回首对差异字符的 ASCII 差值。
- 正确：
  ```c
  int my_strcmp(const char* s1, const char* s2) {
      while (*s1 && *s1 == *s2) { s1++; s2++; }
      return (unsigned char)*s1 - (unsigned char)*s2;
  }
  ```
- 口诀：字符串比较用 `&&` 不是 `&`；返回差值不是 0/1。

### 3. 打印字符串用错格式  [已掌握]
- 现象：`printf("%c", str)` 本想打第 i 个字符，却传了地址。
- 原因：`%c` 要配单个字符 `str[i]`；传 `str` 是地址（且类型也不对）。
- 正确：打单字符 `printf("%c", str[i]);`；打整串 `printf("%s", str);`
- 口诀：`%c` 配字符，`%s` 配地址。

---

## ch13 结构体

### 4. struct 定义位置导致"未声明"  [偶尔忘]
- 现象：在 swap/modify 函数原型之后才定义 struct，编译报 unknown type。
- 原因：C 要求类型先定义后使用；函数原型里用到 struct 就得先定义。
- 正确：把 `typedef struct { ... } S;` 放在所有函数原型和函数体**之前**。
- 口诀：自定义类型一律放文件最前面（见通用铁律）。

### 5. 结构体找最大值标杆写错  [偶尔忘]
- 现象：用 `arr[0]` 当标杆，循环里却仍和 `arr[0]` 比，永远更新不了最大值。
- 原因：标杆应另存为变量 `max`，循环比较 `if (arr[i].score > max.score)`。
- 正确：
  ```c
  S max = arr[0];
  for (int i = 1; i < n; i++)
      if (arr[i].score > max.score) max = arr[i];
  ```
- 口诀：标杆是"变量"不是"下标 0"。

### 6. 指针遍历结构体数组漏 p++  [偶尔忘]
- 现象：`S* p = a;` 循环但忘了 `p++`，只处理第一个或死循环。
- 原因：指针不会自动前进，必须显式 `p++` 或 `p = a + i`。
- 正确：`for (S* p = a; p < a + n; p++) { p->score; }`
- 口诀：指针遍历三件套：初值、条件、前进（见通用铁律）。

---

## ch14 位运算

### 7. 清位漏写按位取反 ~  [偶尔忘] ★高频
- 现象：`num &= (1u << n);` 本想清第 n 位，结果把不该动的位也清了/置了。
- 原因：清位要先取反掩码 `~(1u << n)`，再 `&=`；直接 `&=` 掩码是"只保留第 n 位"。
- 正确：
  ```c
  num |=  (1u << n);   // 置第 n 位
  num &= ~(1u << n);   // 清第 n 位
  num ^=  (1u << n);   // 翻转第 n 位
  (num >> n) & 1       // 取第 n 位
  ```
- 口诀：置位 `|`、清位 `&~`、翻转 `^`、取位 `>> &1`。

### 8. 判断奇偶多挂 num>0  [偶尔忘]
- 现象：`while (num > 0)` 或 `if (num > 0 && num & 1)` 判断奇偶，负奇数直接漏掉。
- 原因：奇偶只看最低位，`num & 1` 对负数同样成立，不该加任何符号判断。
- 正确：`if (num & 1) 奇数; else 偶数;`（与正负无关）
- 口诀：奇偶 = `x & 1`，与正负无关。

---

## ch15 枚举与 static

### 9. 函数该返回字符串却直接 printf  [已掌握]
- 现象：`weekday_name` 函数里直接 `printf` 星期名，调用处却期待返回值。
- 原因：函数职责要单一；返回字符串就 `return "Mon";`，打印交给调用方。
- 正确：`const char* weekday_name(int d) { ...; return name; }` 然后 `printf("%s", weekday_name(d));`
- 口诀：要返回就 return，别在函数里顺手打印。

### 10. 状态机用 s+e 相加判断  [偶尔忘] ★致命
- 现象：用 `switch (s + e)` 或 `if (state == s + e)` 表达"状态+事件"，逻辑全乱。
- 原因：状态和事件是两个维度，必须分开：外层 `switch(状态)`、内层 `if(事件)`。
- 正确：
  ```c
  switch (state) {
      case IDLE: if (e == START) state = RUN; break;
      case RUN:  if (e == STOP)  state = IDLE; break;
      /* ... */
  }
  ```
- 口诀：状态机 = 外层 `switch(状态)` + 内层 `if(事件)`，绝不相加。

### 11. 枚举常量拼写错 RESRT→RESET  [已掌握]
- 现象：手写枚举值拼错，编译报 undeclared identifier。
- 原因：枚举值就是普通标识符，拼错即未定义。
- 正确：定义时一次写对，或靠编译器报错精确定位。
- 口诀：枚举值当变量名对待，拼错必报错。

### 12. static / 全局变量空文件未实现  [已掌握]
- 现象：practice3/4 交上来是空文件，没验证语义。
- 原因：`static` 局部变量跨调用保持值、全局变量是外部链接，需要真实代码验证。
- 正确：
  ```c
  // static 局部：寿命跨调用，只初始化一次
  void f() { static int x = 0; x++; printf("%d\n", x); }
  // 全局：本文件定义 int g; 他文件 extern int g; 共享
  ```
- 口诀：static 局部 = 寿命跨调用；全局前加 static = 只在本文链接（内部链接）。

---

## ch16 宏与多源文件

### 13. 带参宏缺括号 / 传副作用表达式  [偶尔忘] ★高频
- 现象：`#define SQR(x) (x*x)`，`SQR(a+1)` 展开成 `(a+1*a+1)`=a+a+1=7，不是 16；`SQR(++i)` 让 i 被自增两次。
- 原因：宏是**纯文本替换**不是函数——参数不整体加括号会被运算符优先级拆开；传 `++i` 这类带副作用的表达式，替换几次就执行几次。
- 正确：
  ```c
  #define SQR(x) ((x)*(x))          // 参数各加括号 + 整体加括号
  int r = SQR(a+1);                  // → ((a+1)*(a+1)) = 16 ✓
  // 永远别传 ++i/--i/f(x) 进宏
  ```
- 口诀：宏是替换不是函数；参数加括号、整体加括号、不传副作用。

### 14. extern 声明散落在使用处  [已掌握]
- 现象：`main.c` 里手写 `extern int g_count;`，能跑，但声明和接口分离在两处。
- 原因：跨文件共享的变量/函数声明应集中在 `.h` 里，谁 include 谁可见，改一处全局生效。
- 正确：把 `extern int g_count;` 写进 `calc.h`，`main.c` 只 `#include "calc.h"`。
- 口诀：`.h` = 对外接口清单（原型 + extern），`.c` = 实现。

---

## 动态内存（ch16 practice3 预防）

### 铁律（malloc / realloc / free）
- malloc 后必须判 `NULL`；大小写 `n * sizeof(类型)`，绝不写 `malloc(n)`。
- **realloc 永远用临时指针接**：`int* t = realloc(p, newsz); if(!t){free(p);...} else p=t;`——直接 `p=realloc(p,...)` 失败会丢原指针且泄漏。
- realloc 失败时原 `p` 仍有效，要 `free(p)`；成功时旧块已被自动搬走，只留 `p=t`。
- `free(p)` 后立刻 `p=NULL`，杜绝野指针；同一指针 `free` 两次是 UB。
- 输入 n/m 先校验 `n>0`、`m>=0`，防负数转 size_t 爆炸。

---

## ch17 链表（了解级）

### 15. 节点结构自我包含 struct Node stu  [偶尔忘] ★编译不过
- 现象：想让节点存学生信息，写成 `typedef struct Node { struct Node stu; struct Node* next; } Node;`，编译报 "field has incomplete type"。
- 原因：`struct Node stu;` 是「在自己的定义里放一个完整自己」（值成员，不是指针），类型未完成时不能放值，且会无限递归；节点里要放**别的**结构，不能用自身类型名。
- 正确：先定义数据载体 `typedef struct { int id; int score; } stu;`，再 `typedef struct Node { stu data; struct Node* next; } Node;`（字段名别叫 stu，避免混淆）。
- 口诀：节点里放「数据」用其他类型；放「下一个节点」才用 `struct Node*`。

### 16. 读入变量与传参不一致  [已掌握]
- 现象：`scanf("%d",&x); head_insert(&head, id, score);` —— 只读了 x，id/score 根本没读就传进去，值是垃圾。
- 原因：scanf 的变量和后面用的变量要一一对应；多字段就用 `scanf("%d %d",&id,&score)`。
- 正确：读几个就传几个，变量名全程一致。
- 口诀：scanf 读到哪、函数用哪，变量必须同一个。

---

## ch18 链表进阶（删除/插入/查找/长度）

### 17. 尾插找尾循环条件写错 p!=NULL  [偶尔忘] ★段错误
- 现象：tail_insert 里 `while(p!=NULL) p=p->next;` 之后 `p->next=newnode;`，链表非空时直接崩（段错误 / 程序闪退）。
- 原因：`p` 会一路走到 NULL（越过真正的尾节点），此时 `p` 是空指针，`p->next` 解引用空指针 → 段错误。正确做法是停在「最后一个节点」，即它的 `next` 为 NULL 时停。
- 正确：
  ```c
  Node *p=*head;
  while(p->next!=NULL) p=p->next;   // 停在尾节点（其 next 才是 NULL）
  p->next=newnode;                  // 接到尾节点后面
  ```
- 口诀：尾插找「尾节点」用 `p->next!=NULL`；用 `p!=NULL` 会把 p 推过尾变成空，再解引用必崩。

### 18. 空表判断写错 if(newnode==NULL)  [已掌握]
- 现象：tail_insert 开头 `if(newnode==NULL){ *head=newnode; return; }` —— 把"malloc 失败"和"链表为空"混了；且失败时把 head 设成 NULL 毫无意义。
- 原因：`*head==NULL` 才是"空表首插"的分支；`newnode==NULL` 是"malloc 失败"。两个概念别混。
- 正确：空表分支用 `if(*head==NULL){ *head=newnode; return; }`；malloc 失败单独 `if(newnode==NULL){ perror(...); return; }`。
- 口诀：判断"表空"看 head，判断"分配失败"看 newnode。

---

## ch19 文件 IO（9/24）
- **#19 文件读回显陷阱（fgets 读完不打印 buf / 打印越界数组）[偶尔忘]**：`fgets(buf,...)` 读到的内容在 `buf` 里，必须 `printf("%s",buf)` 把它打出来验证"读到的==写入的"；若改成打印原数组 `s[i]`（for 循环后 `i==3` 越界），既没验证文件内容，又访问越界 `s[3]`（数组仅 s[0]~s[2]）属未定义行为。正确：`while(fgets(buf,sizeof(buf),fp)!=NULL) printf("%s",buf);`。口诀：读文件→打 buf；循环变量别当越界下标。

### 二进制 IO 铁律（9/25 未踩坑，预防固化 · M4 V4L2 存图地基）
- 二进制模式必须 `"wb"`/`"rb"`，**不能省 `b`**（Windows 文本模式会做 `\n`↔`\r\n` 转换，破坏二进制数据——存图/存帧必错）。
- `fwrite/fread` 返回值 = 成功读写的**元素个数**（不是字节数），应检查 `ret==nmemb`（或 `==1`）；别当 `void` 忽略。
- 读回目标 `&a` 必须**已分配好空间**，不能读进野指针。
- 读循环用 `while(fread(&s,sizeof(s),1,fp)==1)` 控制（**不用 `feof`**，安全不越界）。
- 二进制文件别用 `fgets/fscanf` 这类文本函数读，混用会乱。

### 20. add() 只填局部变量不入库 [偶尔忘] ★致命
- 现象：综合项目里 `add()` 填好了局部 `STUDENT s`，但**没写 `stulist[stucount]=s; stucount++;`** —— 函数一返回，s 就销毁，列表始终空，保存也是空文件。
- 原因：把"填一个临时结构体"和"把它放进全局数组"当成一步，其实漏了最后入库那两行。
- 正确：`s.status=...; stulist[stucount]=s; stucount++;`（先赋值再存，顺序无所谓，但必须存）。
- 口诀：填完结构体 → 别忘了 `stulist[stucount++]=s;` 这一句才是"真正添加"。

### 21. input_str 把 sizeof(结构体) 当字段长度传 [已掌握] ★溢出风险
- 现象：`input_str("姓名:",s.name,sizeof(STUDENT))` —— 第三个参数应是**目标缓冲区大小**，却传了整个结构体大小（~100），而 `s.name` 只有 50 字节。`fgets` 会往 50 字节里写最多 99 字符 → **缓冲区溢出**。
- 原因：`sizeof(STUDENT)` 是结构体总大小，不是 `s.name` 的大小；调用方要传 `sizeof(s.name)` / `sizeof(s.phone)`。
- 正确：`input_str("姓名:",s.name,sizeof(s.name));` `input_str("电话:",s.phone,sizeof(s.phone));`。
- 口诀：fgets 的 len 参数 = 那个**数组自己**的 sizeof，永远别传外层结构体的 sizeof。

### 22. loadfile 里 `fp==NULL;` 误写比较号 [偶尔忘]
- 现象：关闭文件后写 `fp==NULL;`（双等号），本意是 `fp=NULL;`（单等号赋值）防野指针。
- 原因：`==` 是判断、`=` 是赋值，手滑写成比较，语句无副作用（fp 仍是已 fclose 的野值，本地变量而已影响小，但习惯错误）。
- 正确：`fclose(fp); fp=NULL;`。
- 口诀：置空用单等号；看到 `fp==NULL;` 这种"比较后啥也不做"的语句必是笔误。

## 待补区（之后踩坑往这里加）
