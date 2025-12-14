bool arr[14];
int tot;

void func(int* nums, int numsSize, int k, int s) {
    if(numsSize == k) {
        // for(int i = 0; i < numsSize; i++) {
        //     printf("%d ", arr[i]);
        // }
        // printf("| %d\n", s);
        tot += s;
        return;
    }

    s ^= nums[k];
    arr[k] = true;
    func(nums, numsSize, k + 1, s);

    s ^= nums[k];
    arr[k] = false;
    func(nums, numsSize, k + 1, s);
}

int subsetXORSum(int* nums, int numsSize) {
    tot = 0;
    func(nums, numsSize, 0, 0);

    return tot;
}