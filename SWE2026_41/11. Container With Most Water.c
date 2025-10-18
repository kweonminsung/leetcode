int maxArea(int* height, int heightSize) {
    int start = 0, end = heightSize - 1, max = 0;

    while(start < end) {
        int startH = height[start], endH = height[end];

        int v = (end - start) * (startH > endH ? endH : startH);

        // printf("%d %d | %d\n", start, end, v);
        max = max < v ? v : max;

        if(startH < endH) start++;
        else end--;
    }

    return max;

}