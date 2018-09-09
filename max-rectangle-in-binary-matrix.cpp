int max_rectangle_under_histogram(const vector<int>& hist) {
    int n = hist.size();
    int max_area = 0;
    stack<int> s;
    for(int i = 0; i < n; i++) {
        if(s.empty() || hist[i] >= hist[s.top()]) {
            s.push(i);
            continue;
        }
        int right = i;
        while(!s.empty() && hist[i] < hist[s.top()]) {
            int cur_smallest = hist[s.top()];
            s.pop();
            int left = s.empty() ? -1 : s.top();
            int area = cur_smallest * (right - left - 1);
            max_area = max(area, max_area);
        }
        s.push(i);
    }

    int right = n;
    while(!s.empty()) {
        int cur_smallest = hist[s.top()];
        s.pop();
        int left = s.empty() ? -1 : s.top();
        int area = cur_smallest * (right - left - 1);
        max_area = max(area, max_area);
    }

    return max_area;
}

// Time - O(N), Space - O(N)
// or Time - O(R * C), Space - O(C)
// where R = number of rows, C = number of columns
int Solution::maximalRectangle(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    if(m == 0 || n == 0) {
        return 0;
    }

    int result = max_rectangle_under_histogram(A[0]);
    for(int i = 1; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(A[i][j] == 1) {
                A[i][j] += A[i - 1][j];
            }
        }
        result = max(max_rectangle_under_histogram(A[i]), result);
    }

    return result;
}
