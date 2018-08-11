int Solution::maxArea(vector<int> &A) {
    int n = A.size();
    int start = 0, end = n - 1;
    int area = 0, max_area = 0;
    while(start < end) {
        if(A[start] < A[end]) {
            area = A[start] * (end - start);
            start++;
        }
        else {
            area = A[end] * (end - start);
            end--;
        }
        max_area = max(area, max_area);
    }
    
    return max_area;
}
