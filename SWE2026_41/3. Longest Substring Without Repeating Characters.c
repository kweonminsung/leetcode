int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int lastIdx[300];
    for(int i = 0; i < 300; i++) lastIdx[i] = -1;
    
    int maxLen = 0, start = 0;

    for(int i = 0; i < n; i++) {
        if(lastIdx[s[i]] >= start)
            start = lastIdx[s[i]] + 1;
        
        lastIdx[s[i]] = i;

        int curLen = i - start + 1;
        if(curLen > maxLen) maxLen = curLen;
    }

    return maxLen;
}