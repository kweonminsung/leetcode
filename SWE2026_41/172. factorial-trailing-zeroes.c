int trailingZeroes(int n) {
    int in = 0, jn = 0;
    for(int m = n; m > 1; m--) {
        int i = m, j = m;
        while(i % 2 == 0 && i > 1) {
            i /= 2;
            in++;
        }
        while(j % 5 == 0 && j > 1) {
            j /= 5;
            jn++;
        }
    }

    return in < jn ? in : jn;
}