#define MOD 1000000007

int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    const vector<int> &friends_cap = A;
    const vector<int> &dishes_fill = B;
    const vector<int> &dishes_cost = C;

    int max_cap = *max_element(friends_cap.begin(), friends_cap.end());
    vector<vector<int>> dp(max_cap + 1, vector<int>(dishes_fill.size() + 1, 0));

    for (int cap = 1; cap <= max_cap; cap++) {
        dp[cap][0] = MOD;
    }

    for (int cap = 1; cap <= max_cap; cap++) {
        for (int dish = 1; dish <= dishes_fill.size(); dish++) {
            if (cap - dishes_fill[dish - 1] >= 0) {
                int cur_dish_fill = dishes_fill[dish - 1];
                int cur_dish_cost = dishes_cost[dish - 1];
                dp[cap][dish] =
                    min(dp[cap][dish - 1],
                        dp[cap - cur_dish_fill][dish] + cur_dish_cost);
            } else {
                dp[cap][dish] = dp[cap][dish - 1];
            }
        }
    }

    int result = 0;
    for (const auto &cap : friends_cap) {
        result += dp[cap][dishes_fill.size()];
    }

    return result;
}
