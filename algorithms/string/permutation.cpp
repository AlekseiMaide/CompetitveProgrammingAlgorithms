/**
 * Next lexiographical permutation
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

/**
    Heap's algorithm for generating permutations.
**/
void heapPermutation(string& a, int size) {
    if (size == 1) {
        cout << a << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        heapPermutation(a, size - 1);

        if (size % 2 == 0) {
            // If size is even, swap ith and (size-1)th element
            swap(a[i], a[size - 1]);
        } else {
            // if size is odd, swap 0th and (size-1)th element
            swap(a[0], a[size - 1]);
        }
    }
}
