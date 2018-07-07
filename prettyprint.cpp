// Approach - Each cell's value is one more than its chessboard distance from center
vector<vector<int> > Solution::prettyPrint(int A) {
    int n = 2 * A - 1;
    vector<vector<int>> result(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int dist_x = abs(A - 1 - i);
            int dist_y = abs(A - 1 - j);
            result[i][j] = max(dist_x, dist_y) + 1;
        }
    }
    
    return result;
}
