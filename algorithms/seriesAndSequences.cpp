//Todo: Add arichmetic, geometric, harmonic series.

int sumOfGeometricSeries(int n) {
    return std::pow(2, n) - 1;
}

//Calculate the sum of squares from 1..n
int sumOfSquares(int n) {
    return (n * (n + 1) * (2 * n + 1)) / 6;
}
