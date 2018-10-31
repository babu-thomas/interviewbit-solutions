#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x)                                                               \
    do {                                                                       \
        std::cout << #x << ": " << x << " ";                                   \
    } while (0)
#define DEBUGL(x)                                                              \
    do {                                                                       \
        std::cout << #x << ": " << x << "\n";                                  \
    } while (0)

#define MOD 1000000007

template <typename T> void print_vector(vector<T> a) {
    for (auto &i : a) {
        cout << i << " ";
    }
    cout << "\n";
}

template <typename T> void print_matrix_2d(vector<vector<T>> a) {
    int r = 0;
    for (auto &i : a) {
        cout << r << ": ";
        for (auto &j : i) {
            cout << j << " ";
        }
        r++;
        cout << "\n";
    }
    cout << "\n";
}

int solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
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

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    vector<int> friends_cap{665, 154, 269, 501, 998, 992, 904, 763, 254, 591,
                            869, 843, 683, 708, 410, 88,  352, 566, 497, 252,
                            486, 565, 115, 585, 414, 864, 23,  389, 308};
    vector<int> dishes_fill{1,   586, 973, 418, 573, 193, 416, 566, 815,
                            179, 538, 406, 766, 381, 807, 194, 510, 894,
                            264, 76,  111, 515, 281, 675, 630, 865, 807,
                            213, 887, 914, 520, 433, 501};
    vector<int> dishes_cost{493, 570, 792, 404, 985, 77,  219, 883, 334,
                            343, 649, 714, 151, 561, 942, 763, 825, 737,
                            592, 340, 18,  267, 688, 601, 75,  900, 488,
                            988, 421, 639, 208, 632, 209};

    // Answer - 72225
    cout << solve(friends_cap, dishes_fill, dishes_cost) << "\n";

    return 0;
}
