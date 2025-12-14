bool arr[502];

int next(int n, int k, int prev) {
    while(k) {
        prev = (prev + 1) % n;
        if(arr[prev]) k--;
    };
    return prev;
}

int findTheWinner(int n, int k) {
    for(int i = 0; i < 500; i++) arr[i] = true;

    int remain = n, cur = -1;

    while(remain > 1) {
        int nxt = next(n, k, cur);

        printf("%d ", nxt + 1);
        arr[nxt] = false;
        cur = nxt;
        remain--;
    }

    return next(n, k, cur) + 1;
}