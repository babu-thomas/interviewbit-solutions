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
int solve(vector<int> A) {
    int n = A.size();
    sort(A.begin(), A.end());

    int with_negative = A[0] * A[1] * A[n - 1];
    int without_negative = A[n - 1] * A[n - 2] * A[n - 3];

    return max(with_negative, without_negative);
}

// Time - O(N), Space - O(1)
int solve_linear(const vector<int>& A) {
    int n = A.size();
    int min1 = INT_MAX, min2 = INT_MAX;
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    for(int i = 0; i < n; i++) {
        // Less than both min1 and min2
        if(A[i] <= min1) {
            min2 = min1;
            min1 = A[i];
        }
        // Lies between min1 and min2
        else if(A[i] < min2) {
            min2 = A[i];
        }

        // More than max1, max2, max3
        if(A[i] >= max1) {
            max3 = max2;
            max2 = max1;
            max1 = A[i];
        }
        // Lies between max1 and max2
        else if(A[i] >= max2) {
            max3 = max2;
            max2 = A[i];
        }
        // Lies between max2 and max3
        else if(A[i] > max3) {
            max3 = A[i];
        }
    }

    int with_negative = min1 * min2 * max1;
    int without_negative = max1 * max2 * max3;

    return max(with_negative, without_negative);
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    vector<int> nums{-9, 1, 2, 3, -10};

    cout << solve(nums) << "\n";
    cout << solve_linear(nums) << "\n";

    return 0;
}
