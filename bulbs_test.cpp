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
int solve(const vector<int> &A) {
    const vector<int> &bulbs = A;

    int n = bulbs.size();
    int to_flip = 0, flip_count = 0;

    for (int i = 0; i < n; i++) {
        if (bulbs[i] == to_flip) {
            flip_count++;
            to_flip = 1 - to_flip;
        }
    }

    return flip_count;
}

// Time - O(N), Space - O(1)
int solve2(const vector<int> &A) {
    const vector<int> &bulbs = A;

    int n = bulbs.size();

    if (n == 0) {
        return 0;
    }

    int flip_count = 0;
    if (bulbs[0] == 0) {
        flip_count = 1;
    }

    for (int i = 1; i < n; i++) {
        if (bulbs[i] != bulbs[i - 1]) {
            flip_count++;
        }
    }

    return flip_count;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    vector<int> bulbs{0, 1, 0, 1};

    cout << solve(bulbs) << "\n";
    cout << solve2(bulbs) << "\n";

    return 0;
}
