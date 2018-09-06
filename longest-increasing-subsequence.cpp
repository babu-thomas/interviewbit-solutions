int Solution::lis(const vector<int> &A) {
    int n = A.size();
    if(n == 0) {
        return 0;
    }
    
    vector<int> lis(n, 1);
    int max_len = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(A[i] > A[j]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
        max_len = max(lis[i], max_len);
    }

    return max_len;
}
