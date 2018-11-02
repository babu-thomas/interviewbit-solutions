// Time - O(N * logN), Space - O(N)
// where N = number of elements in grid
int Solution::solve(vector<vector<int> > &A) {
    const vector<vector<int>> &grid = A;

    int rows = A.size();
    int cols = A[0].size();

    vector<vector<int>> hist_heights = grid;

    auto adjacent_ones = [](const int &a, const int &b) {
        if (b == 0) {
            return 0;
        }

        return a + b;
    };

    for (int c = 0; c < cols; c++) {
        int sum = 0;
        for (int r = 0; r < rows; r++) {
            sum = adjacent_ones(sum, grid[r][c]);
            hist_heights[r][c] = sum;
        }
    }

    for (int r = 0; r < rows; r++) {
        sort(hist_heights[r].begin(), hist_heights[r].end(), greater<int>());
    }

    int max_area = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int cur_area = hist_heights[r][c] * (c + 1);
            max_area = max(cur_area, max_area);
        }
    }

    return max_area;
}
