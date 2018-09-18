// Time - O(N*LogN), Space - O(N)
// Got Memory Limit Exceeded
vector<int> Solution::subUnsort(vector<int> &A) {
    int n = A.size();
    vector<int> sorted = A;
    sort(sorted.begin(), sorted.end());
    int start = 0, end = n - 1;
    while(start < end && A[start] == sorted[start]) {
        start++;
    }
    while(start < end && A[end] == sorted[end]) {
        end--;
    }
 
    if(start == end) {
        return {-1};
    }

    return {start, end};
}
