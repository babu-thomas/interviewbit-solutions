void Solution::arrange(vector<int> &A) {
    int n = A.size();
    for(int i = 0; i < n; i++) {
        int index = A[i];
        A[i] = (A[index] % n) * n + A[i];
    }
    
    for(int i = 0; i < n; i++) {
        A[i] = A[i] / n;
    }
}
