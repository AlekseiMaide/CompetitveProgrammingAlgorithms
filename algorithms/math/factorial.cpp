/**
 * Calculate factorial (N!) in O(n) time.
 * Iterative and recursive solutions.
 * (Use iterative for large numbers)
 */


unsigned long long factorial(unsigned long long n) {
    unsigned long long ans = 1;
    for (unsigned long long i = 2; i <= n; ++i) {
        ans *= i;
    }

    return ans;
}

int factorial(int n) {
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}