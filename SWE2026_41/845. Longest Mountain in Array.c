bool is3Mount(int* arr, int top) {
    if(arr[top - 1] >= arr[top] || arr[top] <= arr[top + 1]) return false;
    return true;
}

int longestMountain(int* arr, int arrSize) {
    int top = 1, max = 0;

    while(top < arrSize - 1) {
        if(is3Mount(arr, top)) {
            int start = top - 1, end = top + 1;
            while(start - 1 >= 0 && arr[start] > arr[start - 1]) {
                start--;
            }

            while(end + 1 < arrSize && arr[end] > arr[end + 1]) {
                end++;
            }

            int ln = end - start + 1;
            max = (max < ln) ? ln : max;
        }

        top++;
    }

    return max;
}