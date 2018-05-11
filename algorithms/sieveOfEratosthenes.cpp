/**
 * Generate prime numbers up to n.
 * */

//To Check if number is prime.
//bool *primePtr = sieveOfEratosthenes(1000);
//cout << primePtr[4];

bool *sieveOfEratosthenes(long n)  {
    auto *primes = new bool[n + 1];
    memset(primes, true, sizeof(primes));

    for (size_t p = 2; p * p <= n; ++p) {
        if (primes[p]) {
            for (size_t i = p * 2; i <= n; i += p) {
                primes[i] = false;
            }
        }
    }

    return primes;
}

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