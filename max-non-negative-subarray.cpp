vector<int> Solution::maxset(vector<int> &A) {
    int n = A.size();
    int cur_left = 0, cur_right = 0, max_left = -1, max_right = -1;
    long long cur_sum = 0, max_sum = 0;
    for(cur_right = 0; cur_right < n; cur_right++) {
        if(A[cur_right] < 0) {
            cur_left = cur_right + 1;
            cur_sum = 0;
        }
        else {
            cur_sum += (long long) A[cur_right];
            if(cur_sum > max_sum || (cur_sum == max_sum && 
                cur_right - cur_left + 1 > max_right - max_left + 1)) {
                
                max_left = cur_left;
                max_right = cur_right;
                max_sum = cur_sum;
            }
        }
    }
    
    vector<int> ans;
    if(max_left == -1) {
        return ans;
    }
    
    for(int i = max_left; i <= max_right; i++) {
        ans.push_back(A[i]);
    }
    
    return ans;
}
