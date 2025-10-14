void moveZeroes(int* nums, int numsSize) {
    int idx = 0;

    for(int i = 0; i < numsSize; i++) {
        if(nums[i] == 0) continue;

        int swp = nums[i];
        nums[i] = 0;
        nums[idx++] = swp;
    }
}