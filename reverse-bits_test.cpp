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


uint32_t solve(uint32_t A) {
    uint32_t result = 0;
    for(int i = 0; i < 32; i++, A >>= 1) {
        result <<= 1;
        result |= (A & 1);
    }

    return result;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    // Solution: 964176192
    uint32_t num = 43261596;

    cout << solve(num) << "\n";

    return 0;
}
