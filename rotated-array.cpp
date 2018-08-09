int Solution::findMin(const vector<int> &A) {
    int n = A.size();
    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        int prev = ((mid - 1) % n + n) % n;
        int next = (mid + 1) % n;
        
        if(A[left] <= A[right]) {
            return A[left];
        }
        
        if(A[mid] <= A[prev] && A[mid] <= A[next]) {
            return A[mid];
        }
        
        if(A[mid] <= A[right]) {
            right = mid - 1;
        }
        else if(A[left] <= A[mid]) {
            left = mid + 1;
        }
    }
}
