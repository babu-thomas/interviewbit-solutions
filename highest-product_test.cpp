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

// Time - O(N LogN), Space - O(1)
int solve(vector<int>& A) {
    int n = A.size();
    sort(A.begin(), A.end());

    int with_negative = A[0] * A[1] * A[n - 1];
    int without_negative = A[n - 1] * A[n - 2] * A[n - 3];

    return max(with_negative, without_negative);
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    vector<int> nums{-9, 1, 2, 3, -10};

    cout << solve(nums);

    return 0;
}
