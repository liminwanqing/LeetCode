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
