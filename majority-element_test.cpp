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
    const vector<int>& nums = A;

    int n = nums.size();
    int cur_ele = nums[0], count = 0;
    for(int i = 0; i < n; i++) {
        if(count == 0) {
            cur_ele = nums[i];
            count++;
        }
        else if(nums[i] == cur_ele) {
            count++;
        }
        else {
            count--;
        }
    }

    return cur_ele;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    vector<int> nums {1, 2, 3, 4, 2, 2, 2, 4, 2, 5};

    cout << solve(nums) << "\n";

    return 0;
}
