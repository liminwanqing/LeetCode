/*
给定一个字符串，找出不含有重复字符的最长子串的长度。
示例：
给定 "abcabcbb" ，没有重复字符的最长子串是 "abc" ，那么长度就是3。
给定 "bbbbb" ，最长的子串就是 "b" ，长度是1。
给定 "pwwkew" ，最长子串是 "wke" ，长度是3。请注意答案必须是一个子串，"pwke" 是 子序列  而不是子串。
*/

int lengthOfLongestSubstring(char* s) {
     int len=0;
    char *end=s,*temp;
	char* addressTable[256]={NULL};
	while(*end){
		temp = addressTable[*end];
		addressTable[*end]=end;
		if(temp>=s){
		len=end-s>len?end-s:len;
		s = temp+1;
		}end++;
	}
	len=end-s>len?end-s:len;
	return len;
}


int lengthOfLongestSubstringNew(char* s){
    int table[256] = {0};
    int len = 0;
    int flag = 0;
    int max = 0;
    while (s[flag] != '\0') {
        if (table[s[flag] ]!= 0) {
           if (max < len) {
            max = len;
           }
           if (flag - table[s[flag] ]  + 1=< len) {
               len = flag - table[s[flag] ] + 1;
           } else {
               ++len;
           }
        } else {
            ++len;
        }
        table[s[flag]] = flag + 1;
        ++flag;
    }

    if (len > max) {
        max = len;
    }

    return max;
}
