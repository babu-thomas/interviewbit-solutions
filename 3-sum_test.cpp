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

// Time - O(N^2), Space - O(1)
int solve(vector<int> &A, int B) {
    vector<int> &nums = A;
    int target = B;

    sort(nums.begin(), nums.end());
    int n = nums.size();
    int result = 0;
    int min_diff = INT_MAX;
    for (int first = 0; first < n - 2; first++) {
        int second = first + 1;
        int third = n - 1;

        while (second < third) {
            int sum = nums[first] + nums[second] + nums[third];
            int cur_diff = abs(sum - target);

            if (cur_diff < min_diff) {
                min_diff = cur_diff;
                result = sum;
            }

            if (sum < target) {
                second++;
            } else if (sum > target) {
                third--;
            } else {
                return sum;
            }
        }
    }

    return result;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    vector<int> nums{-1, 2, 1, -4};
    int target = 1;

    cout << solve(nums, target) << "\n";

    return 0;
}
