// Time - O(N), Space - O(1)
int Solution::adjacent(vector<vector<int> > &A) {
    int n = A[0].size();
    int inclusive = max(A[0][0], A[1][0]);
    int exclusive = INT_MIN;
    for(int i = 1; i < n; i++) {
        int exclusive_new = max(exclusive, inclusive);
        if(i == 1) {
            inclusive = max(A[0][i], A[1][i]);
        }
        else {
            inclusive = max(A[0][i], A[1][i]) + exclusive;
        }
        exclusive = exclusive_new;
    }

    return max(exclusive, inclusive);
}
