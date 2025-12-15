int arr[2000];

int nthUglyNumber(int n) {
    arr[1] = 1;

    int i = 1, i2 = 1, i3 = 1, i5 = 1;

    for(int j = 2; j <= n; j++) {
        int n2 = arr[i2] * 2, n3 = arr[i3] * 3, n5 = arr[i5] * 5;
        int next = (n2 < n3 ? (n2 < n5 ? n2 : n5) : (n3 < n5 ? n3 : n5));

        arr[i + 1] = next;
        i++;
        
        if(next == n2) i2++;
        if(next == n3) i3++;
        if(next == n5) i5++;
    }
    return arr[n];
}