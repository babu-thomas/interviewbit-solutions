// Time - O(N), Space - O(N)
int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();

    vector<vector<int>> paths(m, vector<int>(n, 0));

    int not_blocked = 1;
    for(int i = 0; i < m; i++) {
        if(A[i][0] == 1) {
            not_blocked = 0;
        }
        paths[i][0] = not_blocked;
    }
    not_blocked = 1;
    for(int j = 0; j < n; j++) {
        if(A[0][j] == 1) {
            not_blocked = 0;
        }
        paths[0][j] = not_blocked;
    }

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(A[i][j] != 1) {
                paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
            }
        }
    }
    
    return paths[m - 1][n - 1];
}
