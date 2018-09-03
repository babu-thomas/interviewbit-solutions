// Time - O(N^2), Space - O(N)
// or Time - O(R^2 * C), Space - O(R * C)
// where R = number of rows and C = number of columns
int Solution::solve(vector<vector<int> > &A) {
    const vector<vector<int>>& mat = A;
    
    int r = mat.size();
    
    if(r == 0) {
        return 0;
    }
    
    int c = mat[0].size();
    
    if(c == 0) {
        return 0;
    }
    
    vector<vector<int>> sum(r + 1, vector<int>(c + 1, 0));

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            sum[i + 1][j + 1] = mat[i][j] + sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
        }
    }
    
    unordered_map<int, vector<int>> seen;
    int count = 0;

    for(int i = 0; i < r; i++) {
        for(int j = i + 1; j <= r; j++) {
            seen.clear();
            seen[0].push_back(0);
            int cur_count = 0;
            for(int k = 1; k <= c; k++) {
                int diff = sum[j][k] - sum[i][k];
                seen[diff].push_back(k);
            }
            
            for(auto& d: seen) {
                int d_count = d.second.size();
                count = count + (d_count * (d_count - 1)) / 2;
            }
        }
    }

    return count;
}



// Time - O(N^2), Space - O(N)
// or Time - O(R^2 * C), Space - O(R * C)
// where R = number of rows and C = number of columns
int Solution::solve(vector<vector<int> > &A) {
    const vector<vector<int>>& mat = A;
    
    int r = mat.size();
    
    if(r == 0) {
        return 0;
    }
    
    int c = mat[0].size();
    
    if(c == 0) {
        return 0;
    }
    
    vector<vector<int>> sum(r + 1, vector<int>(c + 1, 0));

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            sum[i + 1][j + 1] = mat[i][j] + sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
        }
    }
    
    // This version just has a different way of calculating count. See Interviewbit notes.
    unordered_map<int, int> seen;
    int count = 0;

    for(int i = 0; i < r; i++) {
        for(int j = i + 1; j <= r; j++) {
            seen.clear();
            seen[0] = 1;
            for(int k = 1; k <= c; k++) {
                int diff = sum[j][k] - sum[i][k];
                // This version just has a different way of calculating count. See Interviewbit notes.
                count += seen[diff];
                seen[diff]++;
            }
        }
    }

    return count;
}
