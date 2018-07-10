/*
给定一个字符串，找出不含有重复字符的最长子串的长度。

示例：

给定 "abcabcbb" ，没有重复字符的最长子串是 "abc" ，那么长度就是3。

给定 "bbbbb" ，最长的子串就是 "b" ，长度是1。

给定 "pwwkew" ，最长子串是 "wke" ，长度是3。请注意答案必须是一个子串，"pwke" 是 子序列  而不是子串。
*/

int lengthOfLongestSubstring(char* s) {
    int len = 0, i, j, k, flag = 0, res = 0;
    char* tmp = s;
    while (*tmp++ != '\0') {
        len++;
    }

    if (len == 1) {
        return 1;
    }

    for (i = 0; i < len ; ++i) {
        flag = 0;
        for (j = i+1; j < len && flag != 1; ++j) {
            for (k = j-1; k >= i; --k) {
                if (s[k] == s[j]) {
                    if (res < (j - i)) {
                        res = j-i;
                    }
                    flag = 1;
                    break;
                } else {
                    if (res < j-k+1) {
                        res = j - k + 1;
                    }
                }
            }
        }

    }

    return res;
}
