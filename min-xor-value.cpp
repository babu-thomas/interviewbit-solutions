// Time - O(N), Space - O(1)
int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(), A.end());
    int n = A.size();
    int min_xor = A[0] ^ A[1];
    for(int i = 2; i < n; i++) {
        min_xor = min(A[i - 1] ^ A[i], min_xor);
    }
    return min_xor;
}
