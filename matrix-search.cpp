// Approach - Treat matrix as 1D sorted array, perform binary search
int Solution::searchMatrix(vector<vector<int>> &A, int B) {
    int m = A.size();
    int n = A[0].size();
    int low = 0, high = m * n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        int i = mid / n, j = mid % n;
        if(A[i][j] == B) {
            return 1;
        }
        else if(A[i][j] < B) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    
    return 0;
}
