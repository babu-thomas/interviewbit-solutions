// Time - O(log N), Space - O(log N)
// Calculate x^n % m
int rec(int x, int n, int m) {
    if(n == 0) {
        return 1;
    }
    
    long long y = 0;
    
    if(n % 2 == 0) {
        y = rec(x, n / 2, m);
        y = (y * y) % m;
    }
    else {
        y = x % m;
        y = (y * rec(x, n - 1, m)) % m;
    }
    
    return (y + m) % m;
}

int Solution::Mod(int A, int B, int C) {
    if(A == 0 || A == 1) {
        return A;
    }
    
    return rec(A, B, C);
}
