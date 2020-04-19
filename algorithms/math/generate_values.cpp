/**
 * Generate all divisors for values up to N;
 */
vector<int> generateDivisorCountUpToN(int n) {
    vector<int> divisors(n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            divisors[j]++;
        }
    }

    return divisors;
}

/**
 * generate squares add 1 3 5 7  9  11 13 15 .. etc.
 * which results in     1 4 9 16 25 36 49 64
 */
vector<long long> generateSquaresUpToN(long long n) {
    vector<long long> squares(1, 0);

    long long helper = 1;
    for (long long i = 1; i <= n; i += helper) {
        squares.push_back(i);
        helper += 2;
    }

    return squares;
}
