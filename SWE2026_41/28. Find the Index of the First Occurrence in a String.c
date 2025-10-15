int strStr(char* haystack, char* needle) {
    int hMaxIdx = strlen(haystack) - 1, nMaxIdx = strlen(needle) - 1;

    for(int i = 0; i <= hMaxIdx - nMaxIdx; i++) {
        bool bflag = false;

        for(int j = 0; j <= nMaxIdx; j++) {
            if(haystack[i + j] != needle[j]) {
                bflag = true;
            }
        }

        if(!bflag)
            return i;
        
    }

    return -1;
}