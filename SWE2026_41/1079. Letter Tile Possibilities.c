#define ALPHA_NUM 26

int arr[50];
int dp[10];
int rst;

int fact(int n) {
    return dp[n];
}

void func(int cur) {
    if(ALPHA_NUM == cur) {
        // for(int i = 0; i < ALPHA_NUM; i++) {
        //     printf("%d ", arr[i]);
        // }
        // printf("\n");

        int nums = 0;
        for(int i = 0; i < ALPHA_NUM; i++) nums += arr[i];

        int tot = fact(nums);
        for(int i = 0; i < ALPHA_NUM; i++) {
            tot /= fact(arr[i]);
        }
        rst += tot;
        return;
    }

    int shit = arr[cur];

    for(int i = 0; i <= shit; i++) {
        arr[cur] = i;
        func(cur + 1);
    }
}

int numTilePossibilities(char* tiles) {
    dp[0] = 1;
    for(int i = 1; i <= 8; i++) dp[i] = dp[i - 1] * i;
    for(int i = 0; i < 50; i++) arr[i] = 0;
    rst = 0;

    int len = strlen(tiles);

    for(int i = 0; i < len; i++) {
        arr[tiles[i] - 'A']++;
    }
    // for(int i = 0; i < ALPHA_NUM; i++) printf("%d ", arr[i]);

    func(0);

    return rst - 1;
}