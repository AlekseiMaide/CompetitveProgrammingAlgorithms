/**
 * Calculate modulo for signed numbers.
 */
long long mod(long long a, long long b) {
    long long ret = a % b;
    if (ret < 0)
        ret += b;
    return ret;
}
