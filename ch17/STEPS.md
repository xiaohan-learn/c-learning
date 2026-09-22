# ch17 练习步骤卡：单链表（了解级）

> 目标：吃透单链表「节点结构 + 头插法建表 + 遍历 + 释放」，M1 收尾模块之一。
> 用法：照步骤自己写代码，写完运行对照「验收输出」。先别翻答案，卡住再发我 review。
> 约定：本卡只给「写什么 + 验收 + 坑预警」，不给完整代码（递减骨架，练从零搭程序）。
> 前置：今天 ch16 practice3 的 malloc/free 思维直接复用——节点就是 malloc 出来的，释放就是 free。

---

## 核心概念先记牢（看课跟敲时对照）

### 1. 节点结构
```c
struct Node {
    int data;
    struct Node* next;   // 指向下一个节点的指针，自己包含自己这种类型
};
```
- 注意：`next` 是「指向 Node 的指针」，不是 `Node` 本身（不能在结构里放完整 Node，会无限大）。
- 习惯用 typedef 简写：`typedef struct Node { int data; struct Node* next; } Node;`

### 2. 头指针
- `Node* head = NULL;` —— 空表时 head 为 NULL，这是遍历终止条件。

### 3. 头插法建表（三行，最关键）
```c
Node* nnode = (Node*)malloc(sizeof(Node));  // 1. 申请新节点
nnode->data = x;
nnode->next = head;   // 2. 新节点指向「原来的头」
head = nnode;         // 3. 头指针更新为新节点
```
- 顺序不能反：先让新节点的 next 接上旧头，再改 head，否则丢链。
- 头插 = 逆序：先插的跑到后面去了。输入 1 2 3 → 打印 3 2 1。

### 4. 遍历
```c
for (Node* p = head; p != NULL; p = p->next)
    printf("%d ", p->data);
```
- 条件 `p != NULL` 不是 `p->next != NULL`（后者会漏打最后一个还越界）。

### 5. 释放（先存 next 再 free）
```c
Node* p = head;
while (p) {
    Node* t = p->next;   // 先存下一个
    free(p);
    p = t;               // 再前进
}
head = NULL;             // 释放完头指针置空，防野指针
```
- 致命坑：直接 `free(p); p = p->next;` —— free 之后 p->next 已经是非法的，会崩。必须先存。

---

## 练习1（头插建表 + 遍历）—— 必做
**写什么**
- 定义节点结构 `Node`（data = int，next 指向下一个节点）。
- main 里：读入 `n`，循环 `n` 次，每次读一个整数 `x`，用**头插法**插入链表。
- 建完后遍历打印全部节点。

**验收输出**
- 输入 `3` 再依次输入 `1 2 3` → 打印应为 `3 2 1`（头插逆序，这是头插法的身份证）。
- 输入 `0` 或错误 → head 为 NULL，遍历应什么都不打、不崩。

**坑预警**
- 新节点 `next` 必须接 `head` 再改 `head`，顺序反了丢链。
- malloc 后要不要判 NULL？了解级可省，但养成习惯加 `if(!nnode){perror;return 1;}`。

## 练习2（释放 + 防泄漏）—— 必做
**写什么**
- 在练习1 基础上加 `free_list(Node* head)`，按上面「先存 next 再 free」释放所有节点。
- 释放后 `head = NULL`。

**验收输出**
- 程序正常结束、无崩溃；进阶可用 VS 诊断工具看内存快照前后一致（无泄漏）。

**坑预警**
- 释放顺序：先 `t = p->next` 再 `free(p)`，绝不能 `free(p); p = p->next;`。

## 练习3（可选·缝合：节点存结构体）—— 进阶
**写什么**
- 节点 data 换成 `int score`（或 `struct Student { int id; int score; }` 里挑一个字段），体会节点就是结构体，头插/遍历/释放照旧。

---

## 闭眼复现（晚上 20:00 后，不翻代码）
纸上默写：
1. 节点结构 `struct Node { int data; struct Node* next; };`
2. 头插法三行（新节点 next 接旧头 → 头指针更新）
3. 遍历条件 `p != NULL` 和前进 `p = p->next`
4. 释放为什么「先存 next 再 free」

写不出哪里 = 明天复盘要先补的洞。

---

## git 提交（写完 review 无误后）
```powershell
git add ch17/ && git commit -m "ch17 链表了解级：头插建表+遍历+释放" && git push && git push origin main
```

## 回刷呼应（防前学后忘）
今晚顺手扫一眼 BUG.md：#7 清位漏 `~`（[偶尔忘]）、动态内存铁律（realloc 临时指针 / free 后置 NULL）。链表本身不踩这些，但顺带巩固。
