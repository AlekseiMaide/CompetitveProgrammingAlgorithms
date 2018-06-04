/**
 * O(nW) Classic "Knapsack problem" solution.
 * Used for:
 * Determining if specific sum is possible to combine given set of values.
 */

int n = 4;
int knapsack[n] = {1, 3, 3, 5};
int totalKnapsackSum = accumulate(knapsack, knapsack + n, 0);
bool isPossible[totalKnapsackSum + 1] = {true}; //Set the [0] as true;

bool isKnapsackSumPossible() {
    for (int i = 0; i < n; ++i) {
        for (int j = totalKnapsackSum; j >= 0; --j) {
            if (isPossible[j]) {
                isPossible[j + knapsack[i]] = true;
            }
        }
    }

    //Print possible sums. 0 1 3 4 5 6 7 8 9 11 12
    for (int i = 0; i <= totalKnapsackSum; ++i) {
        if (isPossible[i]) {
            cout << i << " ";
        }
    }
}
