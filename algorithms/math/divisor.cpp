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
