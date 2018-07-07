// Time - O(logN + count)
// Approach - Binary search for the element, then search its left and right
int Solution::findCount(const vector<int> &A, int B) {
    int n = A.size();
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(A[mid] == B) {
            int count = 1;
            // Count occurrences on left side
            int left = mid - 1;
            while(left >= 0 && A[left] == B) {
                count++;
                left--;
            }
            // Count occurrences on right side
            int right = mid + 1;
            while(right < n && A[right] == B) {
                count++;
                right++;
            }
            return count;
        }
        else if(A[mid] < B) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    
    return 0;
}


// Approach - STL :)
int Solution::findCount(const vector<int> &A, int B) {
    auto lower = lower_bound(A.begin(), A.end(), B);
    auto upper = upper_bound(A.begin(), A.end(), B);
    return distance(lower, upper);
}


// Time - O(Log N)
// Approach - Range binary search to find first and last occurrence
int Solution::findCount(const vector<int> &A, int B) {
    int n = A.size();
    int low = 0, high = n - 1;
    int first = -1, last = -1;
    // Find first occurrence
    while(low < high) {
        int mid = (low + high) / 2;
        if(A[mid] < B) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    
    if(A[low] != B) {
        return 0;
    }
    
    first = low;
    //Find last occurrence
    high = n - 1;
    while(low < high) {
        int mid = (low + high) / 2 + 1;
        if(A[mid] > B) {
            high = mid - 1;
        }
        else {
            low = mid;
        }
    }
    
    last = high;
    
    return last - first + 1;
}
