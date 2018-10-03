// Time = O(N * S), Space - O(N * S)
// where N = number of elements, S = total sum of all elements
int Solution::solve(const vector<int> &A) {
    int n = A.size();
    int sum = accumulate(A.begin(), A.end(), 0);
    // dp[i][j].first = max weight possible with weight less than or equal to i using first j items.
    // dp[i][j].second = number of elements used for max weight
    vector<vector<pair<int, int>>> dp((sum / 2) + 1, vector<pair<int, int>>(n + 1, {0, 0}));
    
    // i = current weight limit
    // j = current number of elements
    for(int i = 1; i <= sum / 2; i++) {
        for(int j = 1; j <= n; j++) {
            if(A[j - 1] > i) {
                dp[i][j] = dp[i][j - 1];
            }
            else {
                pair<int, int> incl{dp[i - A[j - 1]][j - 1].first + A[j - 1], 1 + dp[i - A[j - 1]][j - 1].second};
                pair<int, int> excl{dp[i][j - 1].first, dp[i][j - 1].second};

                // Should return true if first element is less than the second element
                auto comp = [](const pair<int, int>& a, const pair<int, int>& b) {
                    if(a.first == b.first) {
                        return a.second < b.second;
                    }
                    return a.first > b.first;
                };

                dp[i][j] = min(incl, excl, comp);

                // Longer version without using custom compare function

                // int incl = dp[i - A[j - 1]][j - 1].first + A[j - 1];
                // int incl_count = 1 + dp[i - A[j - 1]][j - 1].second;
                // int excl = dp[i][j - 1].first;
                // int excl_count = dp[i][j - 1].second;

                // if(incl > excl) {
                //     dp[i][j] = {incl, incl_count};
                // }
                // else if(excl > incl) {
                //     dp[i][j] = {excl, excl_count};
                // }
                // else {
                //     if(incl_count < excl_count) {
                //         dp[i][j] = {incl, incl_count};
                //     }
                //     else {
                //         dp[i][j] = {excl, excl_count};
                //     }
                // }
            }
        }
    }

    return dp[sum / 2][n].second;
}
