
typedef struct {
    int arr[200002];
    int cnt;
} MedianFinder;


MedianFinder* medianFinderCreate() {
    MedianFinder* obj = malloc(sizeof(MedianFinder));
    obj->cnt = 0;
    memset(obj->arr, 0, sizeof(obj->arr));
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    obj->cnt++;
    obj->arr[num + 100000]++;
}

double medianFinderFindMedian(MedianFinder* obj) {
    int c = 0;
    int m1 = -1, m2 = -1;

    for(int i = 0; i < 200002; i++) {
        c += obj->arr[i];

        if(m1 == -1 && c > (obj->cnt - 1) / 2)
            m1 = i;

        if(m2 == -1 && c > obj->cnt / 2)
            m2 = i;

        if(m1 != -1 && m2 != -1)
            break;
    }

    if(obj->cnt % 2 == 1)
        return m2 - 100000;

    return ((m1 + m2) / 2.0) - 100000;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj);
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);
 
 * double param_2 = medianFinderFindMedian(obj);
 
 * medianFinderFree(obj);
*/