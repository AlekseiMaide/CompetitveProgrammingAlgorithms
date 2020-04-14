/**
 * Every 3 consecutive Fibonacci numbers a, b, c satisfies:
 *      a+b = c and a*c = b² ± 1 where the sign alternates between + and -.
 *
 * Substituting the first equation into the second gives a*(a+b) = b² ± 1.
 *
 * Solving for a gives a = (-b ± √(5b² ± 4)) / 2.
 *
 * The ratio of two adjacent numbers in the Fibonacci series rapidly approaches ((1 + sqrt(5)) / 2).
 * If N is divided by ((1 + sqrt(5)) / 2) and then rounded, the resultant number will be the previous Fibonacci number.
 *
 */
int previousFibonacci(int n) {
    double a = n / ((1 + sqrt(5)) / 2.0);
    return round(a);
}

