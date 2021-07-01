/**
    Binary exponentiation O(log N).
**/
int power(int a, int b) {
    int result = 1;

    while (b > 0) {
        if (b % 2 == 1) result *= a;

        a *= a;
        b /= 2;
    }

    return result;
}

/**
    Modular inverse O(log p)

    Euler's theorem (Fermat's little theorem)

    a^(p - 1) = 1

    Generates a relatively prime number?

**/
int inverse(int a, int p) {
    return power(a, p - 2)
}

/* 
    Modular exponentiation in O(log N)

    Iterative Function to calculate (x^y) % p where p is a prime.
*/
int power(long long x, unsigned int y, int p) {
    int res = 1; 
 
    x = x % p; // Update x if it is more than or equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1) {
            res = (res*x) % p;
        }
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    
    return res;
}


/**
    Multiply 2 matricies O(N)
**/
void multiply(vector<vector<int>>& a, vector<vector<int>>& b, vector<vector<int>>& res) {
	int N = b.size();

    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            res[i][j] = 0;
            for (k = 0; k < N; k++)
                res[i][j] += a[i][k] * b[k][j];
        }
    }
}

vector<vector<int>> multiply(vector<vector<int>>& a, vector<vector<int>>& b) {
	int N = b.size();
    
    vector<vector<int>> res(N, vector<int>(N));

    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            res[i][j] = 0;
            for (k = 0; k < N; k++)
                res[i][j] += a[i][k] * b[k][j];
        }
    }
    
    return res;
}

/**
    Exponentiate matrix to some power in O(log N).

    Useful in DP optimization when the state can be expressed as O(1) space.
**/
vector<vector<int>> matrixPower(vector<vector<int>> a, int power) {
    vector<vector<int>> res = {{0,1},{1,1}}; // Change DP state.

    while (power > 0) {
        if (power % 2 == 1) res = multiply(res, a);

        a = multiply(a, a);
        power /= 2;
    }

    return res;
}
