bool isPrime(long n) {
    if(n <= 1) return false;

    for(long i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

bool isUgly(int n) {
    if(n <= 0) return false;
    if(n == 1 || n == 2 || n == 3 || n == 5) return true;

    for(long i = 1; i * i <= n; i++) {
        if(n % i != 0) continue;

        long j = n / i;
        if(
            (i != 2 && i != 3 && i != 5 && isPrime(i)) || (j != 2 && j != 3 && j != 5 && isPrime(j))
        ) return false;
    }

    return true;
}