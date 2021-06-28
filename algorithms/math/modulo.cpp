/**
 * Calculate modulo for signed numbers.
 */
long long mod(long long a, long long b) {
    long long ret = a % b;
    if (ret < 0)
        ret += b;
    return ret;
}

/* 
    Modular exponentiation in O(log N)

    Iterative Function to calculate (x^y) % p where p is a prime.
*/
int power(long long x, unsigned int y, int p) {
    int res = 1; 
 
    x = x % p; // Update x if it is more than or equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1) {
            res = (res*x) % p;
        }
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    
    return res;
}
