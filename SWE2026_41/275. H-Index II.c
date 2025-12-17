int hIndex(int* citations, int citationsSize) {
    int l = 0, r = citationsSize - 1;
    int ans = 0;
    
    while(l <= r) {
        int mid = l + (r - l) / 2;
        int h = citationsSize - mid;

        if(citations[mid] >= h) {
            ans = h;
            r = mid - 1;
        } else l = mid + 1;
    }

    return ans;
}