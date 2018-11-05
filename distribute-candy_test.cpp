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

// Time - O(N), Space - O(N)
int solve(const vector<int> &A) {
    const vector<int> &ratings = A;

    int n = ratings.size();
    vector<int> candies(n, 0);
    candies[0] = 1;
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        } else {
            candies[i] = 1;
        }
    }
    int result = candies[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }

        result += candies[i];
    }

    return result;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    vector<int> ratings1{1, 0, 2};
    vector<int> ratings2{1, 2, 2};

    cout << solve(ratings1) << "\n";
    cout << solve(ratings2) << "\n";

    return 0;
}
