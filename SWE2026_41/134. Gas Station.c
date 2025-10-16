int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int t = 0, g = 0, start = 0;
    for(int i = 0; i < gasSize; i++) {
        int diff = (gas[i] - cost[i]);
        t += diff;
        g += diff;

        if(g < 0) {
            start = i + 1;
            g = 0;
        }
    }

    return t < 0 ? -1 : start;
}