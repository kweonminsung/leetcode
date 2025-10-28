#define MOD 1000000007

char **piz;
int R, C;

// Check if there is at least one apple in the region (r1,c1) ~ (r2-1,c2-1)
bool hasApple(int r1, int c1, int r2, int c2) {
    for (int i = r1; i < r2; i++) {
        for (int j = c1; j < c2; j++) {
            if (piz[i][j] == 'A') return true;
        }
    }
    return false;
}

// Explore all ways to cut the region (r1,c1,r2,c2) into 'cuts' pieces
int backtracking(int r1, int c1, int r2, int c2, int cuts) {
    if (cuts == 1) {
        return hasApple(r1, c1, r2, c2) ? 1 : 0;
    }

    long long total = 0;

    // Try horizontal cuts
    for (int nr = r1 + 1; nr < r2; nr++) {
        // Check if upper piece contain at least one apple
        if (hasApple(r1, c1, nr, c2)) {
            total += backtracking(nr, c1, r2, c2, cuts - 1);
            if (total >= MOD) total %= MOD;
        }
    }

    // Try vertical cuts
    for (int nc = c1 + 1; nc < c2; nc++) {
        // Check if left piece contain at least one apple
        if (hasApple(r1, c1, r2, nc)) {
            total += backtracking(r1, nc, r2, c2, cuts - 1);
            if (total >= MOD) total %= MOD;
        }
    }

    return (int)(total % MOD);
}

int ways(char** pizza, int pizzaSize, int k) {
    piz = pizza;
    R = pizzaSize;
    C = strlen(pizza[0]);

    return backtracking(0, 0, R, C, k);
}
