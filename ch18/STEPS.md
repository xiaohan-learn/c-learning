# ch18 进阶练习卡：链表删除 / 插入 / 查找 / 长度

> 定位：ch18 是 ch17「了解级」的轻量加餐，独立成章（原 ch17/ADV.md 已挪出，ch17 已提交不再改动）。建立在你已会的「头插 + 遍历 + free」之上，全是「遍历 + 改指针」的变体。
> 用法：照步骤自己写，跑通对照「验收输出」，卡住发我 review。递减骨架，不给完整代码。
> 范围：只练 删除指定值 / 指定位置插入 / 按值查找 / 求长度。不碰双向/循环/翻转/排序（留 M6）。

---

## 通用前置（复用 ch17 的节点与头插）
- 节点：`typedef struct Node { int data; struct Node* next; } Node;`
- 头插 `head_insert`、遍历 `print_list`、释放 `free_list` 直接复用 ch17/practice1 写的（新文件里可重写一份，或 `#include` 过来）。
- 所有「改 head 本身」的操作（删头结点、头部插入）都用 `Node** head` 双指针，或在 main 里接收新 head。

---

## 练习1（求长度）—— 必做，最简单
**写什么**
- `int length_list(Node* head)`：遍历计数返回节点数。

**验收输出**
- 建表输入 1 2 3（头插后实际 3 2 1），`length_list` 返回 3。

**坑预警**
- 空表 `head==NULL` 返回 0，别越界。

## 练习2（按值查找）—— 必做
**写什么**
- `Node* find(Node* head, int val)`：找到返回该节点指针，找不到返回 `NULL`；或返回第几个（下标）。

**验收输出**
- 头插 1 2 3（表 3 2 1），`find(head, 2)` 应找到（非 NULL）。

**坑预警**
- 条件 `while(p && p->data != val)`，找到即 `return p`；循环结束 return NULL。

## 练习3（删除指定值结点）—— 必做，重点
**写什么**
- `void delete_val(Node** head, int val)`：删除第一个值为 val 的结点，释放其内存。
- 分两种情况：删的是头结点（head 要指向 head->next）；删的是中间结点（前驱的 next 跳过它）。

**验收输出**
- 表 3 2 1，删 2 → 打印 3 1；删 3（头）→ 打印 2 1；删不存在的 9 → 表不变。

**坑预警（最易错）**
- 删头结点：用双指针 `*head = (*head)->next;` 再 free 原头，否则 head 还指向已释放内存。
- free 顺序：先 `Node* t = p->next`（存后继）→ `free(p)` → 前驱 `prev->next = t`，绝不能 free 后再读 p->next。
- 遍历要保留「前驱指针 prev」，删中间结点靠 prev->next 跳过。

## 练习4（指定位置插入）—— 必做，重点
**写什么**
- `void insert_at(Node** head, int pos, int val)`：在第 pos 个位置插入（pos 从 0 起：0=插到表头，1=插到原第 0 个之后…）。
- pos==0 等同头插；pos>0 遍历走到 pos-1 的前驱，新节点 next 接前驱 next，前驱 next 接新节点。

**验收输出**
- 表 3 2 1，在 pos=1 插 9 → 表变为 3 9 2 1（逆序视角下插在 3 之后）。
- pos=0 插 9 → 9 3 2 1（新头）。

**坑预警**
- pos 越界（>长度）要处理：要么追加到表尾，要么忽略并提示，别让 `p->next` 踩 NULL。
- pos==0 走头插分支，不能进「找前驱」循环（前驱不存在）。

---

## 闭眼复现（练完不翻代码默写）
1. 删除头结点 vs 删除中间结点，代码区别在哪（双指针 / prev->next 跳过）
2. free 前为什么要先存后继指针
3. 指定位置插入 pos==0 为什么要单独处理

---

## git 提交（练完 review 无误后）
```powershell
git add ch18/ && git commit -m "ch18 链表进阶：删除/插入/查找/长度" && git push && git push origin main
```
