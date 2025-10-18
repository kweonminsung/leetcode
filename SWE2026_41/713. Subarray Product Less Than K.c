int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    int start = 0, end = 0, rst = 0;

    for(start = 0; start < numsSize; start++) {
        int product = 1;
        end = start;
        while(end < numsSize) {
            product *= nums[end];
            if(product >= k)
                break;

            rst++;
            end++;
        }
    }
    
    return rst;
}