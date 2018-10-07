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


// Time - O(N), Space - O(1)
int solve(const vector<int>& A) {
    int n = A.size();
    int result = 0;

    // For every bit of an integer
    for(int num = INT_MAX, i = 0; num > 0; num >>= 1, i++) {
        int sum = 0;
        int check_bit = (1 << i);

        // Count how many elements have a set bit at current position
        for(int ele = 0; ele < n; ele++) {
            if(A[ele] & check_bit) {
                sum++;
            }
        }

        if(sum % 3 != 0) {
            result |= check_bit;
        }
    }

    return result;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    vector<int> nums{1, 2, 4, 3, 3, 2, 2, 3, 1, 1};
    cout << solve(nums) << "\n";

    return 0;
}
