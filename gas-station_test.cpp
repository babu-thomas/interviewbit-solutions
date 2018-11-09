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

int solve(const vector<int> &A, const vector<int> &B) {
    const vector<int> &gas = A;
    const vector<int> &cost = B;

    int n = gas.size();
    int tank_gas = 0, total_gas = 0, start_station = 0;
    for (int station = 0; station < n; station++) {
        int current_gas = gas[station] - cost[station];
        tank_gas += current_gas;
        total_gas += current_gas;
        if (tank_gas < 0) {
            start_station = station + 1;
            tank_gas = 0;
        }
    }

    if (total_gas < 0) {
        return -1;
    }

    return start_station;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    // Solution = 3
    vector<int> gas1{1, 2, 3, 4, 5};
    vector<int> cost1{3, 4, 5, 1, 2};

    // Solution = -1
    vector<int> gas2{2, 3, 4};
    vector<int> cost2{3, 4, 3};

    cout << solve(gas1, cost1) << "\n";
    cout << solve(gas2, cost2) << "\n";

    return 0;
}
