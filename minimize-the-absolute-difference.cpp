// Time - O(N), Space - O(1)
int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int p = A.size();
    int q = B.size();
    int r = C.size();
    int i = 0, j = 0, k = 0;
    int min_val, max_val, diff, min_diff = numeric_limits<int>::max();
    while(i < p && j < q && k < r) {
        min_val = min(A[i], min(B[j], C[k]));
        max_val = max(A[i], max(B[j], C[k]));
        diff = max_val - min_val;
        
        if(diff == 0) {
            return 0;
        }
        
        if(diff < min_diff) {
            min_diff = diff;
        }
        
        if(A[i] == min_val) {
            i++;
        }
        else if(B[j] == min_val) {
            j++;
        }
        else {
            k++;
        }
    }
    
    return min_diff;
}
