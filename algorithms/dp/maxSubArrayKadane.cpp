/**
    O(N) Find max continues subarray. (Kadane's algorithm)
*/

/**
 * O(N) Algorithm to find max continues sub-array. (Kadane's algorithm)
 *
 * @param numbers Input array of which to determine the maximum continues sub-array sum.
 * @return Maximum possible sub-array sum.
 */

int maxSubArrayKadane(vector<int> numbers) {
    int maxSum = INT_MIN, sum = 0;

    for (auto number : numbers) {
        sum = max(number, sum + number);
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}


template <class Iterator, class U = typename std::iterator_traits<Iterator>::value_type>
U maxSubArrayT(Iterator first, Iterator last) {
    U sum = U{}, best = U{};
    for (auto it = first; it != last; ++it) {
        sum = max(*it, sum + *it);
        best = max(best, sum);
    }
    return best;
}
