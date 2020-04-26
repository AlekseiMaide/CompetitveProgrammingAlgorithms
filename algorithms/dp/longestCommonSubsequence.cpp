/**
 * Length of longest common subsequence.
 */
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> DP(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                DP[i][j] = 1 + DP[i - 1][j - 1];
            } else {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            cout << DP[i][j] << " ";
//        }
//        cout << endl;
//    }

    return DP[n][m];
}


/**
 * Get the longest common subsequence by backtracking in DP table.
 */
vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {

    int n = a.size();
    int m = b.size();

    vector<vector<int>> DP(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                DP[i][j] = 1 + DP[i - 1][j - 1];
            } else {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    // Build the answer
    vector<int> ans;

    // reduce m & n to find ans.
    int total = DP[n][m];

    while (ans.size() < total) {
        if (DP[n][m] == max(DP[n - 1][m], DP[n][m - 1])) {
            if (DP[n][m - 1] == DP[n][m]) {
                m--;
            } else {
                n--;
            }
        } else {
            ans.push_back(a[n - 1]);
            n--;
            m--;
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}