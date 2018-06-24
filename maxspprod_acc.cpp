int Solution::maxSpecialProduct(vector<int> &A)
{
    int n = A.size();
    vector<int> rsv(n, 0);
    vector<int> lsv(n, 0);
    
    stack<int> s;
    s.push(0);
    for(int i = 1; i < n; i++) {
        while(!s.empty() && A[i] > A[s.top()]) {
            rsv[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()) {
        rsv[s.top()] = 0;
        s.pop();
    }
    
    s.push(n - 1);
    for(int i = n - 2; i >= 0; i--) {
        while(!s.empty() && A[i] > A[s.top()]) {
            lsv[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()) {
        lsv[s.top()] = 0;
        s.pop();
    }
    
    long long prod = -1;
    for(int i = 0; i < n; i++) {
        prod = max(prod, 1LL * lsv[i] * rsv[i]);
    }
    
    return prod % 1000000007;
}
