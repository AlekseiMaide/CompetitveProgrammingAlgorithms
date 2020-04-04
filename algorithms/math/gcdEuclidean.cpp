/**
    O(log n) Euclidean algorithm for finding greatest common divisor.

    By adding a check for whether one value is bigger than the second on, one can improve the performance in half of the cases.
*/

int gcdEuclidean(int a, int b) {
    if (a == 0) return b;
    return gcdEuclidean(b % a, a);
}
