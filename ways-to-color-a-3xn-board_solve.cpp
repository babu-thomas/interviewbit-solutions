#define MOD 1000000007

// Time - O(N), Space - O(1)
int Solution::solve(int A) {
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
