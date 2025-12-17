int heap[100010];
int size;

int top() {
    if(size == 0) return -1;
    return heap[1];
}

void push(int val) {
    int i = ++size;
    while(i > 1 && val > heap[i / 2]) {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = val;
}

int pop() {
    if(size == 0) return -1;
    int parent = 1, child = 2;
    int val = heap[1];
    int tmp = heap[size--];

    while(child <= size) {
        if(child < size && heap[child] < heap[child + 1]) child++;
        if(tmp >= heap[child]) break;
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = tmp;
    return val;
}

int findKthLargest(int* nums, int numsSize, int k) {
    memset(heap, 0, sizeof(heap));
    size = 0;

    for(int i = 0 ; i < numsSize; i++) {
        push(nums[i]);
    }

    int rst = -1;
    while(k--) {
        rst = pop();
    }

    return rst;
}