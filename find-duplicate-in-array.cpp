// Time - O(N), Space - O(1)
int Solution::repeatedNumber(const vector<int> &A) {
    int slow = A[0];
    int fast = A[0];
    do {
        slow = A[slow];
        fast = A[A[fast]];
    }
    while(slow != fast);

    int p1 = A[0];
    int p2 = slow;
    while(p1 != p2) {
        p1 = A[p1];
        p2 = A[p2];
    }
    
    return p1;
}
