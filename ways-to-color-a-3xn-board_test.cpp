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

    if (A == 1) {
        return color3 + color2;
    }

    for (int i = 2; i <= A; i++) {
        long long new_color3 = (11 * color3 + 10 * color2) % MOD;
        color2 = (5 * color3 + 7 * color2) % MOD;

        color3 = new_color3;
    }

    return (color3 + color2) % MOD;
}

struct Triplet {
    int first;
    int second;
    int third;
};

vector<Triplet> generate_single_triplets() {
    vector<Triplet> result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (j != i) {
                for (int k = 0; k < 4; k++) {
                    if (k != j) {
                        result.push_back({i, j, k});
                    }
                }
            }
        }
    }

    return result;
}

bool is_compatible(const vector<Triplet> &triplets, int prev, int cur) {
    if (triplets[prev].first == triplets[cur].first ||
        triplets[prev].second == triplets[cur].second ||
        triplets[prev].third == triplets[cur].third) {
        return false;
    }

    return true;
}

// Time - O(N), Space - O(N)
int solve_dp(int A) {
    vector<Triplet> triplets = generate_single_triplets();
    int n = triplets.size();
    if (A == 1) {
        return n;
    }

    unordered_map<int, int> prev_count;
    unordered_map<int, int> cur_count;
    for (int i = 0; i < n; i++) {
        prev_count[i] = 1;
    }

    for (int column = 2; column <= A; column++) {
        for (int cur_triplet = 0; cur_triplet < n; cur_triplet++) {
            long long triplet_count = 0;
            for (int prev_triplet = 0; prev_triplet < n; prev_triplet++) {
                if (is_compatible(triplets, prev_triplet, cur_triplet)) {
                    triplet_count += prev_count[prev_triplet];
                    triplet_count %= MOD;
                }
            }
            cur_count[cur_triplet] = triplet_count;
        }

        prev_count = cur_count;
    }

    long long result = 0;
    for(auto& t: cur_count) {
        result = (result + t.second) % MOD;
    }

    return result;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int num = 100;

    cout << solve(num) << "\n";
    cout << solve_dp(num) << "\n";

    return 0;
}
