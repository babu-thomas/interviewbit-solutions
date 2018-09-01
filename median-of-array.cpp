int find_kth_element(const vector<int>&a, const vector<int>& b, int k) {
    // First array has minimum elements in left side when all of second array's elements
    // are in left side
    int min_i = max(0, k - (int)b.size());
    // First array has maximum elements in left side when all k elements are from first
    // array or whole first array is on left side if its size is less than k.
    int max_i = min(k, (int)a.size());
    while(min_i <= max_i) {
        int i = (min_i + max_i) / 2;
        int j = k - i;

        if(i > 0 && j < b.size() && a[i - 1] > b[j]) {
            max_i = i - 1;
        }
        else if(j > 0 && i < a.size() && b[j - 1] > a[i]) {
            min_i = i + 1;
        }
        else {
            if(i ==  0) {
                return b[k - 1];
            }
            if(j == 0) {
                return a[k - 1];
            }

            return max(a[i - 1], b[j - 1]);
        }
    }
    // Shouldn't reach here
    return 0;
}

// Time - O(log(min(M, N)), Space - O(1)
// where M and N are the sizes of the two arrays
double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int m = A.size();
    int n = B.size();
    
    if(m > n) {
        return findMedianSortedArrays(B, A);
    }

    if((m + n) % 2 != 0) {
        return find_kth_element(A, B, (m + n + 1) / 2);
    }

    double first = find_kth_element(A, B, (m + n) / 2);
    double second = find_kth_element(A, B, (m + n) / 2 + 1);

    return (first + second) / 2;
}
