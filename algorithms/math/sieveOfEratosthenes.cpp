/**
 * O(N log (log N)) can be modified to O(N)
 * Fastest known algorithm for generating primes.
 * Up to N=10 million in reasonable timeframe.
 * */

//Print the primes to stdout.
void sieveOfEratosthenes(long n)  {
    bool primes[n + 1];
    memset(primes, true, sizeof(primes));

    for (size_t p = 2; p * p <= n; ++p) {
        if (primes[p]) {
            for (size_t i = p * 2; i <= n; i += p) {
                primes[i] = false;
            }
        }
    }

    for (long i = 1; i <= n; ++i) {
        if (primes[i]) {
            cout << i << endl;
        }
    }
}