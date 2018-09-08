#define MOD 1000000007

// Time - O(N^2), Space - O(N)
// where N is the given number
int Solution::chordCnt(int A) {
    vector<long long> dp(A + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= A; i++) {
        for(int j = 0; j < i; j++) {
            dp[i] += (dp[j] * dp[i - 1 - j]) % MOD;
            dp[i] %= MOD;
        }
    }
    
    return dp[A];
}
