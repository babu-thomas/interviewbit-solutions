// Time - Exponential, Space - O(N)
void rec(int count, int open, int closed, string current, vector<string>& result) {
    if(closed == count) {
        result.push_back(current);
        return;
    }
    
    if(open < count) {
        rec(count, open + 1, closed, current + "(", result);
    }
    
    if(open > closed) {
        rec(count, open, closed + 1, current + ")", result);
    }
}

vector<string> Solution::generateParenthesis(int A) {
    vector<string> result;
    
    if(A > 0) {
        rec(A, 0, 0, "", result);
    }
    
    return result;
}
