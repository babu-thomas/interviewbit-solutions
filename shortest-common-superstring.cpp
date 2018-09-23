struct Element {
    int last;
    int len;
};

int overlap(const vector<string>& ss, vector<vector<int>>& overlap_seen,
    int first, int second) {
    if(first == -1) {
        return ss[second].size();
    }
    
    if(overlap_seen[first][second] != -1) {
        return overlap_seen[first][second];
    }

    string a = ss[first];
    string b = ss[second];

    if(a.find(b) != string::npos) {
        return 0;
    }

    int min_len = min(a.size(), b.size());
    int max_overlap = 0;
    for(int i = 1; i <= min_len; i++) {
        int pos = a.rfind(b.substr(0, i));
        if(pos + i == a.size()) {
            max_overlap = max(i, max_overlap);
        }
    }

    string leftover = b.substr(max_overlap, b.size() - max_overlap);
    
    overlap_seen[first][second] = b.size() - max_overlap;
    return overlap_seen[first][second];
}

// Time - O(N * 2^N), Space - O(2^N)
// where N = number of strings
int Solution::solve(vector<string> &A) {
    int n = A.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j && A[i].find(A[j]) != string::npos) {
                swap(A.back(), A[j]);
                A.pop_back();
                n--;
                i--;
                j--;
            }
        }
    }
    
    vector<vector<int>> overlap_seen(n, vector<int>(n, -1));
    vector<Element> dp(pow(2, n), {-1, INT_MAX});
    dp[0] = {-1, 0};
    for(int mask = 0; mask < pow(2, n); mask++) {
        for(int j = 0; j < n; j++) {
            if((mask & (1 << j)) == 0) {
                int new_len = dp[mask].len + overlap(A, overlap_seen, dp[mask].last, j);
                int old_len = dp[mask | (1 << j)].len;

                if(new_len <= old_len) {
                    dp[mask | (1 << j)] = {j, new_len};
                }
            }
        }
    }
    
    return dp[pow(2, n) - 1].len;
}
