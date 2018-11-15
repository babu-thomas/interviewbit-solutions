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
int solve(int A) {
    int target = A;

    vector<int> fib;
    int first = 1, second = 1;
    while (first <= target) {
        fib.push_back(first);
        int third = first + second;
        first = second;
        second = third;
    }
    int count = 0;
    for (int i = fib.size() - 1; i >= 0; i--) {
        int cur_fib = fib[i];
        while (cur_fib <= target) {
            target -= cur_fib;
            count++;
        }
        if (target == 0) {
            break;
        }
    }

    return count;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int target = 121;

    cout << solve(target) << "\n";

    return 0;
}
