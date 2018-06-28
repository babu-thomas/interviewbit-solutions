// Time - O(MxN), Space - O(M + N)

void Solution::setZeroes(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    vector<bool> zero_rows(m);
    vector<bool> zero_cols(n);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(A[i][j] == 0) {
                zero_rows[i] = true;
                zero_cols[j] = true;
            }
        }
    }
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(zero_rows[i] || zero_cols[j]) {
                A[i][j] = 0;
            }
        }
    }
}


// Time - O(MxN), Space - O(1)

void Solution::setZeroes(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    
    bool first_row_zero = false, first_col_zero = false;
    // Find whether first row contains zero
    for(int j = 0; j < n; j++) {
        if(A[0][j] == 0) {
            first_row_zero = true;
            break;
        }
    }
    // Find whether first column contains zero
    for(int i = 0; i < m; i++) {
        if(A[i][0] == 0) {
            first_col_zero = true;
            break;
        }
    }
    
    // Store info about zeros in first row and column
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(A[i][j] == 0) {
                A[i][0] = 0;
                A[0][j] = 0;
            }
        }
    }
    
    // Set other rows and columns to zero
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(A[i][0] == 0 || A[0][j] == 0) {
                A[i][j] = 0;
            }
        }
    }
    
    //Set first row to zero if needed
    if(first_row_zero) {
        for(int j = 0; j < n; j++) {
            A[0][j] = 0;
        }
    }
    
    //Set first column to zero if needed
    if(first_col_zero) {
        for(int i = 0; i < m; i++) {
            A[i][0] = 0;
        }
    }
}
