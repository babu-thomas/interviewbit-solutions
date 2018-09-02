// Time - O(N^2), Space - O(N^2)
// Hashing solution
int Solution::solve(const vector<int> &A) {
    int n = A.size();
    if(n <= 2) {
        return n;
    }

    unordered_map<int, vector<pair<int, int>>> diffs;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            diffs[A[j] - A[i]].push_back({i, j});
        }
    }

    int max_len = 2;
    for(auto& each_diff : diffs) {
        vector<int> lengths(n, 1);
        for(auto& each_pair : each_diff.second) {
            lengths[each_pair.second] = lengths[each_pair.first] + 1;
        }

        max_len = max(*max_element(lengths.begin(), lengths.end()), max_len);
    }

    return max_len;
}



// Time - O(N^3), Space - O(1)
// Bruteforce solution
int Solution::solve(const vector<int> &A) {
    int n = A.size();
    if(n <= 2) {
        return n;
    }
    int max_len = 2;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int diff = A[j] - A[i];
            int cur_len = 2;
            int last = A[j];
            for(int k = j + 1; k < n; k++) {
                if(A[k] - last == diff) {
                    cur_len++;
                    last = A[k];
                }
            }
            max_len = max(cur_len, max_len);
        }
    }

    return max_len;
}



// Time - O(N^3), Space - O(N^2)
// DP solution
int Solution::solve(const vector<int> &A) {
    int n = A.size();
    if(n <= 2) {
        return n;
    }

    vector<vector<int>> dp(n, vector<int>(n, 2));
    int max_len = 2;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int need = 2 * A[i] - A[j];
            int pos = -1;
            for(int k = i - 1; k >= 0; k--) {
                if(A[k] == need) {
                    pos = k;
                    break;
                }
            }

            if(pos != -1) {
                dp[i][j] = max(dp[i][j], dp[pos][i] + 1);
            }
            max_len = max(dp[i][j], max_len);
        }
    }

    return max_len;
}



// Time - O(N^2), Space - O(N^2)
// DP with hashing solution
int Solution::solve(const vector<int> &A) {
    int n = A.size();
    if(n <= 2) {
        return n;
    }

    vector<vector<int>> dp(n, vector<int>(n, 2));
    unordered_map<int, int> pos;
    int max_len = 2;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int need = 2 * A[i] - A[j];
            if(pos.count(need)) {
                dp[i][j] = max(dp[i][j], dp[pos[need]][i] + 1);
            }
            max_len = max(dp[i][j], max_len);
        }
        pos[A[i]] = i;
    }

    return max_len;
}
