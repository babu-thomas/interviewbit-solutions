int segregate(vector<int> &A)
{
    int j = 0;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] > 0) {
            if(i != j) {
                swap(A[i], A[j]);
            }
            j++;
        }
    }
    
    return j;
}

int Solution::firstMissingPositive(vector<int> &A) {
    int n = segregate(A);
    for(int i = 0; i < n; i++) {
        int index = abs(A[i]) - 1;
        if(index < n && A[index] > 0) {
            A[index] = -A[index];
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(A[i] > 0) {
            return i + 1;
        }
    }
    
    return n + 1;
}


// Another shorter way

int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    for(int i = 0; i < n; i++) {
        if(A[i] > 0 && A[i] <= n) {
            int index = A[i] - 1;
            if(A[index] != A[i]) {
                swap(A[i], A[index]);
                i--;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(A[i] != i + 1) {
            return i + 1;
        }
    }
    
    return n + 1;
}