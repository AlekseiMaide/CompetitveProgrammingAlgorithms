/**
 * Build the solution from bottom up by considering strings of length 1, then 2 etc.
 * State of DP is described by maintaining maximum result of DP[start][end] ranges.
 */
int longestPalindromeSubseq(string s) {
    int n = s.size();
    int DP[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            DP[i][j] = 0;
        }
    }

    // Init diagonal to 1, because strings of length 1 are all palindromes.
    for (int i = 0; i < n; i++) {
        DP[i][i] = 1;
    }

    int j = 1;
    for (int i = 1; i <= n; i++) { // Outer loop is distance. Iterate diagonally. (0, 1) (1, 2) (2, 3)
        for (int j = i; j < n; j++) {

            if (s[j - i] == s[j]) {
                DP[j - i][j] = DP[j - i + 1][j - 1] + 2;
            } else {
                DP[j - i][j] = max(DP[j - i + 1][j], DP[j - i][j - 1]);
            }

        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << DP[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return DP[0][n - 1];
}