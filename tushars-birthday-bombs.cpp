// DP solution - Memory Limit Exceeded
// Time - O(A * N), Space - O(A * N)
// where N = number of elements in B
vector<int> Solution::solve(int A, vector<int> &B) {
    reverse(B.begin(), B.end());
    int n = B.size();
    vector<vector<int>> dp(A + 1, vector<int>(n + 1, 0));
    vector<vector<bool>> selected(A + 1, vector<bool>(n + 1, false));
 
    for(int i = 1; i <= A; i++) {
        for(int j = 1; j <= n; j++) {
            if(B[j - 1] <= i) {
                int cur = 1 + dp[i - B[j - 1]][j];
                int prev = dp[i][j - 1];
                if(cur >= prev) {
                    dp[i][j] = cur;
                    selected[i][j] = true;
                }
                else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
            else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
 
    vector<int> result;
    int i = A, j = n;
    while(i != 0 && j != 0) {
        if(selected[i][j]) {
            result.push_back(n - j);
            i -= B[j - 1];
        }
        else {
            j--;
        }
    }
 
    return result;
}



// Greedy solution - Accepted
// Time - O(N), Space - O(N)
vector<int> Solution::solve(int A, vector<int> &B) {
    int resistance = A;
    const vector<int>& strengths = B;
    
    int n = strengths.size();
    int min_strength = INT_MAX;
    int min_strength_pos = -1;
    unordered_map<int, int> positions;
    for(int i = 0; i < n; i++) {
        if(positions.count(strengths[i]) == 0) {
            positions[strengths[i]] = i;
        }
        if(strengths[i] < min_strength) {
            min_strength = strengths[i];
            min_strength_pos = i;
        }
    }

    int max_kicks = resistance / min_strength;
    int max_kicks_strength = max_kicks * min_strength;

    int min_ele = INT_MAX;
    vector<int> new_strengths;
    for(int i = 0; i < min_strength_pos; i++) {
        if(strengths[i] < min_ele) {
            min_ele = strengths[i];
            new_strengths.push_back(strengths[i]);
        }
    }

    vector<int> result;
    int count = 0;
    for(int i = 0; i < new_strengths.size(); i++) {
        while(max_kicks_strength - min_strength + new_strengths[i] <= resistance
            && count < max_kicks) {
            
            result.push_back(positions[new_strengths[i]]);
            count++;
            max_kicks_strength = max_kicks_strength - min_strength + new_strengths[i];
        }
    }

    if(result.size() < max_kicks) {
        int left = max_kicks - result.size();
        for(int i = 0; i < left; i++) {
            result.push_back(min_strength_pos);
        }
    }

    return result;
}



// Shorter and clearer Greedy solution - Accepted
// Time - O(N), Space - O(N)
vector<int> Solution::solve(int A, vector<int> &B) {
    int resistance = A;
    const vector<int>& strengths = B;
    
    int n = strengths.size();
    int min_strength = INT_MAX;
    vector<int> candidate_strengths;
    unordered_map<int, int> idx_of;

    for(int i = 0; i < n; i++) {
        if(strengths[i] < min_strength) {
            min_strength = strengths[i];
            candidate_strengths.push_back(strengths[i]);
            idx_of[strengths[i]] = i;
        }
    }

    n = candidate_strengths.size();
    vector<int> result;
    int i = 0;
    while(i < n) {
        int cur_strength = candidate_strengths[i];
        if(cur_strength <= resistance) {
            int resistance_left = resistance - cur_strength;
            int max_hits = resistance / min_strength;
            int cur_hits = 1 + resistance_left / min_strength;
            if(cur_hits == max_hits) {
                result.push_back(idx_of[cur_strength]);
                resistance -= cur_strength;
                continue;
            }
        }
        i++;
    }

    return result;
}
