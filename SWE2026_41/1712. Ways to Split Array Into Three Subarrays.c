int sum[100001];

int waysToSplit(int* nums, int numsSize) {
    sum[0] = nums[0];
    for (int i = 1; i < numsSize; i++)
        sum[i] = sum[i - 1] + nums[i];

    int left = 0, rst = 0, startR = 0, endR = 0;

    while (left < numsSize - 1) {
        if (startR < left + 1) startR = left + 1;
        if (endR < left + 1) endR = left + 1;

        while (startR < numsSize - 1 && sum[left] > sum[startR] - sum[left]) {
            startR++;
        }
        while (endR < numsSize - 1 && sum[endR] - sum[left] <= sum[numsSize - 1] - sum[endR]) {
            endR++;
        }
        if(startR < endR) {
            rst = (rst + endR - startR) % 1000000007;
        }
        left++;
    }

    return rst;
}