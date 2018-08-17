void rec(const vector<int>& elements, int pos, vector<int>& current,
    vector<vector<int>>& result) {
        
    int n = elements.size();
    if(pos == n) {
        result.push_back(current);
        return;
    }
    
    result.push_back(current);
    for(int i = pos; i < n; i++) {
        current.push_back(elements[i]);
        rec(elements, i + 1, current, result);
        current.pop_back();
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>> result;
    vector<int> current;
    
    rec(A, 0, current, result);
    
    return result;
}


// Shorter version
void rec(const vector<int>& elements, int pos, vector<int>& current,
    vector<vector<int>>& result) {

    result.push_back(current);
    for(int i = pos; i < elements.size(); i++) {
        current.push_back(elements[i]);
        rec(elements, i + 1, current, result);
        current.pop_back();
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>> result;
    vector<int> current;
    
    rec(A, 0, current, result);
    
    return result;
}
