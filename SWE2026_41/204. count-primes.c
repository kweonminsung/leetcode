int arr[5000001];

bool isPrime(int n) {
    if(n == 1) return false;

    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int countPrimes(int n) {
    if(n == 0) return 0;

    arr[1] = 1;

    for(int i = 2; i * i < n; i++) {
        if(!isPrime(i)) continue;

        for(int j = 2; j * i < n; j++) arr[j * i] = 1;
    }

    int tot = 0;
    for(int i = 1; i < n; i++) if(!arr[i]) tot++;
    return tot;
}