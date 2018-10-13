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

// Time - O(Log A), Space - O(1)
// where A = dividend
int solve(int A, int B) {
    int dividend = A;
    int divisor = B;

    if ((divisor == 0) || (dividend == INT_MIN && divisor == -1)) {
        return INT_MAX;
    }

    bool is_negative = ((dividend < 0) ^ (divisor < 0));
    long long divisor_abs = labs(divisor);
    long long dividend_abs = labs(dividend);
    int result = 0;
    while (dividend_abs >= divisor_abs) {
        long long multiple = divisor_abs, multiplier = 1;
        while (dividend_abs >= (multiple << 1)) {
            multiple <<= 1;
            multiplier <<= 1;
        }
        dividend_abs -= multiple;
        result += multiplier;
    }

    if (is_negative) {
        return -result;
    }

    return result;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int dividend = 43;
    int divisor = -8;
    cout << solve(dividend, divisor) << "\n";

    return 0;
}
