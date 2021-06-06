/**
 * Binary Indexed Tree (Fenwick tree)
 *
 * Reference:
 * http://zobayer.blogspot.com/2013/11/various-usage-of-bit.html
 * https://www.topcoder.com/community/competitive-programming/tutorials/binary-indexed-trees/
 * https://www.youtube.com/watch?v=uSFzHCZ4E-8
 *
 * Problems:
 *
 * https://codeforces.com/contest/276/problem/C <-- Counting frequencies of accessing elements.
 */

class Fenwick {
    int MaxIdx;
    vector<long long> tree;
public:
    Fenwick(int MaxIdx);
    Fenwick(int MaxIdx, long long *numbers);
    void update(int idx, long long val);
    long long query(int idx);
};

Fenwick::Fenwick(int MaxIdx) {
    this->MaxIdx = MaxIdx - 1;

    tree = vector<long long>(MaxIdx);
}

void Fenwick::update(int idx, long long val) {
    while (idx <= MaxIdx) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

long long Fenwick::query(int idx) {
    long long sum = 0;
    while (idx > 0) {
        sum += tree[idx];
        idx -= (idx & -idx);
    }

    return sum;
}

/**
 * Build Fenwick tree in O(N) time.
 *
 * NB: Requires testing.
 */
Fenwick::Fenwick(int MaxIdx, long long *numbers) {
    this->MaxIdx = MaxIdx - 1;

    tree = vector<long long>(MaxIdx);
    tree.assign(numbers, numbers + MaxIdx);

    for (int i = 1; i < MaxIdx; i++) {
        int parentIdx = i + (i & -1);
        if (parentIdx < MaxIdx) {
            tree[parentIdx] += tree[i];
        }
    }
}