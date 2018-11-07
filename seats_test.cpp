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

#define MOD 10000003

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
int solve(const string& A) {
    const string& seats = A;

    int n = seats.size();
    int occupied_total = count(seats.begin(), seats.end(), 'x');
    int occupied_found = 0, vacant_seats = 0;
    int result = 0;
    for(int i = 0; i < n; i++) {
        if(seats[i] == 'x') {
            if(vacant_seats != 0) {
                int right_moves = (occupied_found % MOD) * (vacant_seats % MOD);
                int left_moves = ((occupied_total - occupied_found) % MOD) * (vacant_seats % MOD);
                result = (result + min(right_moves, left_moves)) % MOD;
                vacant_seats = 0;
            }

            occupied_found++;
        }
        else {
            vacant_seats++;
        }
    }

    return result;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    string seats = "....x..xx...x..";
    string seats2 = "..xx...xx..xx..xxx...";

    cout << solve(seats) << "\n";
    cout << solve(seats2) << "\n";

    return 0;
}
