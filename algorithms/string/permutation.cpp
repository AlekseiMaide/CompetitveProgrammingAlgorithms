/**
 * Next lexiographical permutation
 *
 * Approximate description:
 * Find position that is lexiographically greater than previous
 * and based on data find where the next permutation happens.
 *
 * return false if no permutation exists.
 */
void swap(string& s, int a, int b) {
    char tmp = s[a];
    s[a] = s[b];
    s[b] = tmp;
}

bool nextPermutation(string &s) {

    int n = s.size();
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] < s[i + 1]) {
            for (int j = n - 1;; j--) {
                if (s[j] > s[i]) {
                    swap(s, i, j);
                    for (i++, j = n - 1; i < j; i++, j--) {
                        swap(s, i, j);
                    }

                    return true;
                }
            }
        }
    }

    return false;
}
