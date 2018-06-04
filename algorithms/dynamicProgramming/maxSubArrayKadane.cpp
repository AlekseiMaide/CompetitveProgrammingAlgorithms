/**
    O(N) Find max continues subarray. (Kadane's algorithm)
*/

/**
    Returns maximum continues sub-array.

    @param array.
    @return Sum of maximum subarray
*/
int maxSubArray(int array[]) {
    int best = 0, sum = 0;
    int n = sizeof(array) / sizeof(array[0]);
    for (size_t i = 0; i < n; i++) {
        sum = max(array[i], sum + array[i]);
        best = max(best, sum);
    }
    return best;
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
