int stack[1001];
int stackSize;
int visit[1001];
void push(int val) {
    stack[stackSize++] = val;
}
int pop() {
    return stack[--stackSize];
}
int top() {
    return stack[stackSize];
}
int size() {
    return stackSize;
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    memset(stack, 0, sizeof(stack));
    memset(visit, 0, sizeof(visit));
    stackSize = 0;

    push(0); visit[0] = 1;
    while(size()) {
        int cur = pop();
        for(int i = 0; i < roomsColSize[cur]; i++) {
            int nextRoom = rooms[cur][i];
            
            if(!visit[nextRoom]) {
                visit[nextRoom] = 1;
                push(nextRoom);
            }
        }
    }

    for(int i = 0; i < roomsSize; i++) {
        if(!visit[i]) return false;
    }
    return true;
}