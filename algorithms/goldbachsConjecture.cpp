/**
 * Even N as the sum of two prime numbers
 * @param n Even number to find sum of.
 * @param primes Array of bool values denoting primes. (Sieve of eratosthenses)
 */
void goldbachsConjecture(int n, bool primes[]) {
    if (n <= 2 || n % 2 != 0) {
        cout << "Has to be even number or greater than 3.";
        return;
    }

    for (int i = 0; i <= n / 2; ++i) {
        if (!primes[i]) continue;

        int diff = n - i;
        if (primes[diff]) {
            cout << i << " " << diff;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long n = 100000;
    bool primes[n + 1];
    memset(primes, true, sizeof(primes));

    for (size_t p = 2; p * p <= n; ++p) {
        if (primes[p]) {
            for (size_t i = p * 2; i <= n; i += p) {
                primes[i] = false;
            }
        }
    }

    goldbachsConjecture(100, primes);
}

