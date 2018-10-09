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

// Time - O(Log N), Space - O(1)
int solve(int A) {
    long long result = 0;
    while (A != 0) {
        result = result * 10 + (A % 10);
        A /= 10;
    }

    if (result > INT_MAX || result < INT_MIN) {
        return 0;
    }

    return result;
}

// Time - O(Log N), Space - O(1)
int solve_better(int A) {
    int result = 0;
    bool is_negative = false;
    if (A < 0) {
        is_negative = true;
        A *= -1;
    }

    while (A > 0) {
        int digit = A % 10;
        // Check if adding a new digit will cause the reverse to overflow
        if (result > (INT_MAX / 10) ||
            (result == (INT_MAX / 10) && digit > (INT_MAX % 10))) {
            return 0;
        }

        result = result * 10 + digit;
        A /= 10;
    }

    if (is_negative) {
        return -result;
    }

    return result;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int n = -199999998;
    cout << solve(n) << "\n";
    cout << solve_better(n) << "\n";

    return 0;
}
