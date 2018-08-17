void rec(vector<int>& numbers, int pos, vector<vector<int>>& result) {
    int n = numbers.size();
    if(pos == n) {
        result.push_back(numbers);
        return;
    }
    
    for(int i = pos; i < n; i++) {
        swap(numbers[pos], numbers[i]);
        rec(numbers, pos + 1, result);
        swap(numbers[pos], numbers[i]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> result;
    rec(A, 0, result);
    
    return result;
}
