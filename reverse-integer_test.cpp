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

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int n = -199999998;
    cout << solve(n) << "\n";

    return 0;
}
