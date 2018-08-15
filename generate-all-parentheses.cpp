// Time - O(N), Space - O(N)
int Solution::isValid(string A) {
    int n = A.size();
    unordered_map<char, char> closes{{'}', '{'}, {']', '['}, {')', '('}};
    stack<int> s;
    for(int i = 0; i < n; i++) {
        if(A[i] == '(' || A[i] == '{' || A[i] == '[') {
            s.push(A[i]);
        }
        else {
            if(s.empty() || closes[A[i]] != s.top()) {
                return 0;
            }
            s.pop();
        }
    }
    
    if(!s.empty()) {
        return 0;
    }
    
    return 1;
}
