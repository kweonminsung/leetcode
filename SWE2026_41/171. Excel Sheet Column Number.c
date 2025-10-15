int power(int n) {
    int rst = 1;

    while(n--)
        rst *= 26;

    return rst;
}

int titleToNumber(char* columnTitle) {
    int maxIdx = strlen(columnTitle) - 1, tot = 0;

    for(int i = maxIdx, j = 0; i >= 0; i--, j++) {
        tot += power(j) * (int)(columnTitle[i] - 'A' + 1);
    }

    return tot;
}