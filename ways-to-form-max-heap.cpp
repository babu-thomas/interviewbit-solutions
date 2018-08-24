#define MOD 1000000007

// Calculate nCk % MOD
vector<vector<long long>> calculate_combinations(int n, int k) {
    vector<vector<long long>> result(n + 1, vector<long long>(k + 1));
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= min(i, k); j++) {
            if(j == 0 || j == i) {
                result[i][j] = 1;
            }
            else {
                result[i][j] = (result[i - 1][j - 1] % MOD + result[i - 1][j] % MOD) % MOD;
            }
        }
    }
    
    return result;
}

int left_subtree_elements(int total_elements) {
    if(total_elements == 1) {
        return 0;
    }

    int height = log2(total_elements);
    int max_elements_last = (1 << height);
    int actual_elements_last = total_elements - ((1 << height) - 1);

    // If last level is more than half filled
    if(actual_elements_last >= (max_elements_last / 2)) {
        return (1 << height) - 1;
    }
    // If last level is less than half filled
    return (1 << height) - 1 - (max_elements_last / 2) + actual_elements_last;
}

int Solution::solve(int A) {
    vector<vector<long long>> ncr = calculate_combinations(A, A);
    
    vector<long long> dp(A + 1);
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= A; i++) {
        int left = left_subtree_elements(i);
        dp[i] = ((ncr[i - 1][left] * dp[left]) % MOD * dp[i - 1 - left]) % MOD;
    }

    return dp[A];
}
