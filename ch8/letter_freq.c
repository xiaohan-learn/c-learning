#include <stdio.h>

#define MAX_LEN 200

// 统计 str 中每个英文字母出现的次数，结果存入 freq[26]
// freq[0] 对应 'a'，freq[1] 对应 'b'，……，freq[25] 对应 'z'
// 大小写算同一个字母（'A' 和 'a' 都计入 freq[0]）
// TODO: 实现这个函数
void letter_freq(char str[], int freq[]) {
    for(int i=0;str[i]!='\0';i++){
       char c=str[i];
       if(c>='a'&&c<='z'){
        freq[c-'a']++;
       }else if(c>='A'&&c<='Z'){
        freq[c-'A']++;
       }
    
    }
    // 提示：
    // 1. 用循环遍历 str，直到遇到 '\0' 结束
    // 2. 遇到小写字母 c：idx = c - 'a'，然后 freq[idx]++
    // 3. 遇到大写字母同理：idx = c - 'A'
    // 4. 不是字母的字符（空格、标点、数字）直接跳过

}

int main() {
    char str[MAX_LEN];
    int freq[26] = {0};   // 先把 26 个计数器清零

    printf("请输入一行英文: ");
    // 读入一整行（含空格）。scanf 的 %[^\n] 表示"读到换行符之前"
    scanf(" %199[^\n]", str);

    letter_freq(str, freq);

    printf("字母出现频率:\n");
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            printf("%c: %d\n", 'a' + i, freq[i]);
        }
    }
    return 0;
}
