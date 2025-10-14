int dp[10001];

int maxSubArray(int* nums, int numsSize) {
    int best = nums[0];
    dp[0] = nums[0];

    for(int i = 1; i < numsSize; i++) {
        if(nums[i] > dp[i - 1] + nums[i]) {
            dp[i] = nums[i];
        } else {
            dp[i] = dp[i - 1] + nums[i];
        }

        if(best < dp[i])
            best = dp[i];
    }

    return best;
}