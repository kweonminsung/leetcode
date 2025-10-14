int singleNumber(int* nums, int numsSize) {
    int shit = nums[0];

    for(int i = 1; i < numsSize; i++) {   
        shit ^= nums[i];
    }
    return shit;
}