int queue[2001];
int start, end;

int indegree[2001];
int edge[2001][5001];
int edgeSize[2001];
int used[2001];

void push(int val) {
    queue[end++] = val;
}
int pop() {
    return queue[start++];
}
int size() {
    return end - start;
}
int front() {
    return queue[start];
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    memset(queue, 0, sizeof(queue));
    memset(indegree, 0, sizeof(indegree));
    memset(edge, 0, sizeof(edge));
    memset(edgeSize, 0, sizeof(edgeSize));
    memset(used, 0, sizeof(used));
    start = end = 0;

    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        edge[b][edgeSize[b]++] = a;
        indegree[a]++;
    }

    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0)
            push(i);
    }

    while (size() > 0) {
        int cur = pop();
        used[cur] = 1;

        for (int i = 0; i < edgeSize[cur]; i++) {
            int nxt = edge[cur][i];
            if (--indegree[nxt] == 0)
                push(nxt);
        }
    }

    for (int i = 0; i < numCourses; i++) {
        if (!used[i])
            return false;
    }
    return true;
}