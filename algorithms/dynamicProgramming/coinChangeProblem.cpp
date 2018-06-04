/**
 * Classic "coin change problem".
 * Given coin face values, determine way min/max counts of coins to give change.
 */

int const n = 5;
int coins[n] = {1, 2, 3, 5, 11};

int const nCounts = 10001;
int counts[nCounts] = {0}; //Set the [0] value to 0.

//Iterative approach.
int minimumCoinCount(int totalSum) {
    for (int i = 1; i <= nCounts; ++i) {
        counts[i] = numeric_limits<int>::max();
        for (auto coin : coins) {
            if (i - coin  >= 0) {
                counts[i] = min(counts[i], counts[i - coin ] + 1);
            }
        }
    }

    return counts[totalSum];
}
