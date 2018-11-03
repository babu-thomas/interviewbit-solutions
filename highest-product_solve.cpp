// Time - O(N LogN), Space - O(1)
int Solution::maxp3(vector<int> &A) {
    int n = A.size();
    sort(A.begin(), A.end());

    int with_negative = A[0] * A[1] * A[n - 1];
    int without_negative = A[n - 1] * A[n - 2] * A[n - 3];

    return max(with_negative, without_negative);
}
