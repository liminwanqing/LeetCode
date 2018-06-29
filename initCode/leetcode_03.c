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
