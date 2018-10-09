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

template <typename T> void print_vector(vector<T> a) {
    for (auto &i : a) {
        cout << i << " ";
    }
    cout << "\n";
}

// Time - O(N logN), Space - O(N)
int solve(const vector<int> &A) {
    int n = A.size();
    if (n == 0) {
        return -1;
    }
    if (n == 1) {
        return 0;
    }

    vector<pair<int, int>> to_sort;
    for (int i = 0; i < n; i++) {
        to_sort.push_back({A[i], i});
    }
    sort(to_sort.begin(), to_sort.end());

    int max_idx = to_sort[n - 1].second;
    int result = 0;
    for (int i = n - 2; i >= 0; i--) {
        result = max(max_idx - to_sort[i].second, result);
        max_idx = max(to_sort[i].second, max_idx);
    }

    return result;
}

// Time - O(N), Space - O(N)
int solve_linear(const vector<int> &A) {
    int n = A.size();
    if (n == 0) {
        return -1;
    }
    if (n == 1) {
        return 0;
    }

    // left_min[i] = min(A[0] to A[i])
    vector<int> left_min(n);
    left_min[0] = A[0];
    for (int i = 1; i < n; i++) {
        left_min[i] = min(A[i], left_min[i - 1]);
    }

    // right_max[i] = max(A[i] to A[n - 1])
    vector<int> right_max(n);
    right_max[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        right_max[i] = max(A[i], right_max[i + 1]);
    }

    int result = 0;
    int i = 0, j = 0;
    while (i < n && j < n) {
        if (left_min[i] <= right_max[j]) {
            result = max(j - i, result);
            j += 1;
        } else {
            i++;
        }
    }

    return result;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    vector<int> nums{9, 2, 3, 4, 5, 6, 7, 8, 18, 0};
    cout << solve(nums) << "\n";
    cout << solve_linear(nums) << "\n";

    return 0;
}
