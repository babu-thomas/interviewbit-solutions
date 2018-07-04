// Euclid's algorithm, Time - O(log B)

// Recursive
int rec(int A, int B) {
    return B == 0 ? A : rec(B, A % B);
}

int Solution::gcd(int A, int B) {
    return rec(A, B);
}

// Iterative
int Solution::gcd(int A, int B) {
    while(B != 0) {
        int remainder = A % B;
        A = B;
        B = remainder;
    }
    
    return A;
}
