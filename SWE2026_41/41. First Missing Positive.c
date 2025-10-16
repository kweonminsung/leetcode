#define SHIT 20000

int firstMissingPositive(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= 0 || nums[i] > numsSize)
            nums[i] = SHIT;
    }

    for (int i = 0; i < numsSize; i++) {
        int val = abs(nums[i]);
        if (val >= 1 && val <= numsSize)
            nums[val - 1] = -abs(nums[val - 1]);
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0)
            return i + 1;
    }

    return numsSize + 1;
}
