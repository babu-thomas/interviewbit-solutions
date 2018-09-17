// Time - O(N), Space - O(1)
void Solution::nextPermutation(vector<int> &A) {
    int n = A.size();
    int i = n - 2;
    while(i >= 0 && A[i + 1] <= A[i]) {
        i--;
    }
    if(i >= 0) {
        int j = n - 1;
        while(j >= 0 && A[j] <= A[i]) {
            j--;
        }
        swap(A[i], A[j]);
    }
    reverse(A.begin() + i + 1, A.end());
    
    return;
}
