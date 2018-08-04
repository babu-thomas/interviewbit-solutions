vector<int> Solution::flip(string A) {
    vector<int> trans;
    for(auto& i: A) {
        if(i == '0') {
            trans.push_back(1);
        }
        else {
            trans.push_back(-1);
        }
    }
    
    vector<int> ans;
    int left = 0, left_ans = 0, right_ans = 0, sum = 0, max_sum = numeric_limits<int>::min();
    for(int i = 0; i < trans.size(); i++) {
        sum += trans[i];
        if(sum < 0) {
            left = i + 1;
            sum = 0;
        }
        else if(sum > max_sum) {
            left_ans = left;
            right_ans = i;
            max_sum = sum;
        }
    }
    
    if(max_sum <= 0) {
        return ans;
    }
    
    ans.push_back(left_ans + 1);
    ans.push_back(right_ans + 1);
    
    return ans;
}
