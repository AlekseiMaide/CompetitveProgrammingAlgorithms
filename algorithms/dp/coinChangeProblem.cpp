/**
 * Classic "coin change problem".
 *
 * Given coin face values, determine min/max counts of coins to give change.
 *
 * Similar to 0-1 knapsack problem in DP
 */
int minimumCoinCount(int targetSum, int coins[]) {
    int counts[targetSum + 1] = {0};

    // i - is treated as target sum for current iteration.
    for (int i = 1; i <= targetSum; i++) {
        counts[i] = numeric_limits<int>::max();

        for (int coin : coins) {
            // IndexOutOfBounds - Not reaching 0, but going farther.
            if (i - coin >= 0) {
                counts[i] = min(counts[i], counts[i - coin] + 1);
            }
        }
    }

    return counts[targetSum];
}

int nWaysToMakeChange1D(int amount, int coins[]) {
    int dp[] = new int[amount + 1];
    dp[0] = 1;

    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i-coin];
        }
    }

    return dp[amount];
}


int nWaysToMakeChange2D(int amount, int coins[]) {
    int DP[coins.length + 1][amount + 1] = {0};

    for (int i = 0; i <= coins.length; i++) {
        DP[i][0] = 1; // Init first column.
    }

    for (int row = 1; row <= coins.length; row++) {
        for (int col = 1; col <= amount; col++) {
            if (col >= coins[row - 1]) {
                DP[row][col] = DP[row - 1][col] + DP[row][col - coins[row- 1]];
            } else {
                DP[row][col] = DP[row - 1][col];
            }
        }
    }

    return DP[coins.length][amount];
}