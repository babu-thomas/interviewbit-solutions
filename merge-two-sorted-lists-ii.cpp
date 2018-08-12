void Solution::merge(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int m = B.size();
    vector<int> result(n + m);
    int i = 0, j = 0;
    int k;
    for(k = 0; k < n + m; k++) {
        if(j == m || (i < n && A[i] < B[j])) {
            result[k] = A[i++];
        }
        else {
            result[k] = B[j++];
        }
    }
    
    while(j < m) {
        result[k++] = B[j++];
    }
    
    A = result;
}
