int Solution::removeDuplicates(vector<int> &A) {
    int n = A.size();
    
    if(n == 0) {
        return 0;
    }
    
    int i = 0;
    for(int j = 1; j < n; j++) {
        if(A[i] != A[j]) {
            swap(A[i + 1], A[j]);
            i++;
        }
    }
    A.resize(i + 1);
    return i + 1;
}
