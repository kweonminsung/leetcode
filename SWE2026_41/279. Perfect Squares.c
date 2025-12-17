int queue[10001];
int start = 0, end = 0;
int visit[10001];
void push(int val) {
    queue[end++] = val;
}
int pop() {
    return queue[start++];
}
int front() {
    return queue[start];
}
int size() {
    return end - start;
}

int numSquares(int n) {
    memset(queue, 0, sizeof(queue));
    start = 0, end = 0;
    memset(visit, 0, sizeof(visit));

    push(0);
    visit[0] = 1;

    int level = 0;

    while (size() > 0) {
        int curSize = size();
        level++;

        for (int i = 0; i < curSize; i++) {
            int cur = pop();

            for (int j = 1; j * j <= n; j++) {
                int next = cur + j * j;

                if (next == n)
                    return level;

                if (next < n && !visit[next]) {
                    visit[next] = 1;
                    push(next);
                }
            }
        }
    }
    return level;

}