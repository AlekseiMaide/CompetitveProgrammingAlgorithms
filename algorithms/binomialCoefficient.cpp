/**
 *  Returns the value of Binomial Coefficient ( n | k )
 *  Calculate value of n! / (k! * (n - k)!)
 *  Used for:
 *  Combinatorics (Combinations of k in n)
 *  Binomial Theorem for Binomial expansion.
 *  Generation of Pascals Triangle.
 */

int binomialCoefficient(int n, int k) {
    int coefficient = 1;

    if ( k > n - k ) {
        k = n - k;
    }

    for (int i = 0; i < k; ++i) {
        coefficient *= (n - i);
        coefficient /= (i + 1);
    }

    return coefficient;
}

/**
 * Pascals triangle
 * Is generated using binomial coefficients.
 * Used for:
 * Binomial expansion.
 */

void printPascal(int n) {
    for (int line = 0; line < n; ++line) {
        for (int i = 0; i <= line; ++i) {
            cout << binomialCoefficient(line, i) << " ";
        }
        cout << "\n";
    }
}
