// Time - O(N), Space - O(1)
vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    vector<int> result(n);
    stack<int> smaller;
    for(int i = 0; i < n; i++) {
        while(!smaller.empty() && smaller.top() >= A[i]) {
            smaller.pop();
        }
        
        if(smaller.empty()) {
            result[i] = -1;
        }
        else {
            result[i] = smaller.top();
        }
        
        smaller.push(A[i]);
    }
    
    return result;
}

// Shorter version
vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    vector<int> result(n);
    stack<int> smaller;
    smaller.push(-1);
    for(int i = 0; i < n; i++) {
        if(A[i] > smaller.top()) {
            result[i] = smaller.top();
            smaller.push(A[i]);
        }
        else {
            smaller.pop();
            i--;
        }
    }
    
    return result;
}

