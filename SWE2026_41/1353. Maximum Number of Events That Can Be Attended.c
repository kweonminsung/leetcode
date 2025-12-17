int heap[100010];
int size;

int top() {
    if(size == 0) return -1;
    return heap[1];
}

void push(int val) {
    int i = ++size;
    while(i > 1 && val < heap[i / 2]) {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = val;
}

int pop() {
    if(size == 0) return -1;
    int parent = 1,child = 2;
    int val = heap[1];
    int tmp = heap[size--];

    while(child <= size) {
        if(child < size && heap[child] > heap[child + 1]) child++;
        if(tmp <= heap[child]) break;
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = tmp;
    return val;
}

int cmp(const void* a, const void* b) {
    int* ia = *(int**)a;
    int* ib = *(int**)b;

    return ia[0] - ib[0];
}

int maxEvents(int** events, int eventsSize, int* eventsColSize) {
    memset(heap, 0, sizeof(heap));
    size = 0;

    qsort(events, eventsSize, sizeof(int*), cmp);

    int ans = 0, i = 0;
    for(int today = 0; today <= 100000; today++) {
        while(i < eventsSize && events[i][0] <= today)
            push(events[i++][1]);

        if(size != 0) {
            pop();
            ans++;
        }
        while(size != 0 && top() <= today) pop();
    }
    return ans;
}