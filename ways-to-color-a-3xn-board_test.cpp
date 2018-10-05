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
int solve(int A) {
    long long color3 = 24;
    long long color2 = 12;

    if(A == 1) {
        return color3 + color2;
    }

    for(int i = 2; i <= A; i++) {
        long long new_color3 = (11 * color3 + 10 * color2) % MOD;
        color2 = (5 * color3 + 7 * color2) % MOD;

        color3 = new_color3;
    }

    return (color3 + color2) % MOD;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int num = 100000;

    cout << solve(num) << "\n";

    return 0;
}
