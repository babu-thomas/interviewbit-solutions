// Use a modified binary search. For a given mid point we know that one of the subarrays
// on the left or right will be sorted. Compare B to the end points of this sorted subarray
// and adjust the search space accordingly.
int Solution::search(const vector<int> &A, int B) {
    int n = A.size();
    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        // Case 1: A[mid] is the required element
        if(A[mid] == B) {
            return mid;
        }
        
        // Case 2: The right subarray is sorted
        if(A[mid] <= A[right]) {
            // Case 2A: B lies in the right subarray
            if(A[mid] < B && B <= A[right]) {
                left = mid + 1;
            }
            // Case 2B: B doesn't lie in the right subarray, search in the left subarray
            else {
                right = mid - 1;
            }
        }
        // Case 3: The left subarray is sorted
        else if(A[left] <= A[mid]) {
            // Case 3A: B lies in the left subarray
            if(A[left] <= B && B < A[mid]) {
                right = mid - 1;
            }
            // Case 3B: B doesn't lie in the left subarray, search in the right subarray
            else {
                left = mid + 1;
            }
        }
    }
    
    return -1;
}
