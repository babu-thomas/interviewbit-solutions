// Time - O(N^2), Space - O(1)
int Solution::nTriang(vector<int> &A) {
    sort(A.begin(), A.end());
    int n = A.size();
    long long count = 0;
    for(int i = n - 1; i >= 2; i--) {
        int l = 0, r = i - 1;
        while(l < r) {
            long long sum = A[l] + A[r];
            if(sum > A[i]) {
                count += (r - l);
                r--;
            }
            else {
                l++;
            }
        }
    }
    
    return count % 1000000007;
}
