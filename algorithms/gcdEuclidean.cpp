/**
    O(log n) Euclidean algorithm for finding greatest common divisor.
*/

int gcdEuclidean(int a, int b) {
    if (a == 0) return b;
    return gcdEuclidean(b % a, a);
}
