#define MOD 1000000007

int R, C;

// apples[r][c]: number of apples from (r,c) to the bottom-right corner.
int apples[55][55];
// dp[r][c][k]: number of ways to cut the pizza starting from cell (r,c) into k pieces.
int dp[55][55][15];

// Check if there is at least one apple in the region (r1,c1) ~ (r2-1,c2-1)
bool hasApple(int r1, int c1, int r2, int c2) {
    int count = apples[r1][c1]
              - apples[r2][c1]
              - apples[r1][c2]
              + apples[r2][c2];
    return count > 0;
}

// Recursive DP with memoization
int backtracking(int r, int c, int k) {
    // If no apples remain, there is no valid way.
    if (apples[r][c] == 0) return 0;

    // Base case: last piece, valid if it has any apple.
    if (k == 1) return 1;

    if (dp[r][c][k] != -1) return dp[r][c][k];

    long long total = 0;

    // Try horizontal cuts
    for (int nr = r + 1; nr < R; nr++) {
        // Check if upper piece contain at least one apple
        if (hasApple(r, c, nr, C)) {
            total += backtracking(nr, c, k - 1);
            total %= MOD;
        }
    }

    // Try vertical cuts
    for (int nc = c + 1; nc < C; nc++) {
        // Check if left piece contain at least one apple
        if (hasApple(r, c, R, nc)) {
            total += backtracking(r, nc, k - 1);
            total %= MOD;
        }
    }

    return dp[r][c][k] = (int)total;
}

int ways(char **pizza, int pizzaSize, int k) {
    R = pizzaSize;
    C = strlen(pizza[0]);

    memset(apples, 0, sizeof(apples));
    memset(dp, -1, sizeof(dp));

    // Build prefix-sum of apples
    for (int r = R - 1; r >= 0; r--) {
        for (int c = C - 1; c >= 0; c--) {
            apples[r][c] = (pizza[r][c] == 'A')
                         + apples[r + 1][c]
                         + apples[r][c + 1]
                         - apples[r + 1][c + 1];
        }
    }

    return backtracking(0, 0, k);
}
