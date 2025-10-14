// 보이어 무어 다수 투표 알고리즘
int majorityElement(int* nums, int numsSize) {
    int cnt = 1, cand = nums[0];

    for(int i = 1; i < numsSize; i++) {
        if(cand == nums[i]) {
            cnt++;
        } else {
            cnt--;
        }

        if(cnt == 0) {
            cand = nums[i];
            cnt = 1;
        }
    }

    return cand;
}