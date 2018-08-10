int Solution::lengthOfLastWord(const string A) {
    int n = A.size();
    int i = n - 1;
    int end = i;
    // Trim trailing spaces
    while(i >= 0 && A[i] == ' ') {
        i--;
        end--;
    }
    for( ; i >= 0; i--) {
        if(A[i] == ' ') {
            return end - i;
        }
    }
    
    return end + 1;
}
