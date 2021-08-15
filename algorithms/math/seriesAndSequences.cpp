//Todo: Add arichmetic, geometric, harmonic series.

int sumOfGeometricProgression(int firstTerm, int ratio, int n) {
    return (firstTerm * (1 - pow(ratio, n))) / (1 - ratio);
}

double sumOfGeometricProgression(double firstTerm, double ratio) {
    return firstTerm / (1 - ratio);
}

//Calculate the sum of squares from 1..n
int sumOfSquares(int n) {
    return (n * (n + 1) * (2 * n + 1)) / 6;
}
