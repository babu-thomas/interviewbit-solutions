// Time - O(N), Space - O(1)
void Solution::rotate(vector<vector<int> > &A) {
    int rows = A.size();
    if(rows == 0) {
        return;
    }
    
    int cols = A[0].size();

    // Transpose
    for(int i = 0; i < rows; i++) {
        for(int j = i; j < cols; j++) {
            swap(A[i][j], A[j][i]);
        }
    }
    // Reverse rows
    for(int i = 0; i < rows; i++) {
        for(int j = 0, k = cols - 1; j < k; j++, k--) {
            swap(A[i][j], A[i][k]);
        }
    }
}
