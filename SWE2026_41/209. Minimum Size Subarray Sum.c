int minSubArrayLen(int target, int* nums, int numsSize) {
    int start = 0, end = 0, sum = 0;
    int rst = numsSize + 1;

    while (end < numsSize) {
        sum += nums[end++];

        while (sum >= target) {
            int len = end - start;
            if (len < rst) rst = len;

            sum -= nums[start++];
        }
    }

    return (rst == numsSize + 1) ? 0 : rst;
}