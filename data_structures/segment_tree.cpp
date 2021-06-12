/**
    Segment tree

    Reference:
    https://codeforces.com/blog/entry/18051

**/

const int N = 1e5;  // limit for array size
int n;  // array size
int nums[2 * N];

/**
    Build the tree.

    Function '+' can be replaced with another cummutative function such as min/max.
    Must also initialize the array to INF or -INF instead of 0.

**/
void build() {
  for (int i = n - 1; i > 0; --i) nums[i] = nums[i<<1] + nums[i<<1|1];
}

/**
    set value at position p

    Note: p^1 is the position of the sibling node.
**/
void modify(int p, int value) {
  for (nums[p += n] = value; p > 1; p >>= 1) nums[p>>1] = nums[p] + nums[p^1];
}

/**
    sum on interval [l, r) <-- open interval, end is exclusive
**/
int query(int l, int r) {
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += nums[l++];
    if (r&1) res += nums[--r];
  }
  return res;
}

int main() {
    cin >> n;

 	for (int i = 0; i < n; i++) {
 		cin >> nums[n + i];
 	}

  	build();
  	modify(0, 1);
  	cout << (query(0, 5)) << endl;
  	return 0;
}
