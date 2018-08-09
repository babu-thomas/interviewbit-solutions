int Solution::isPalindrome(string A) {
    int left = 0, right = A.size() - 1;
    while(left < right) {
        while(left < right && !isalnum(A[left])) {
            left++;
        }
        while(left < right && !isalnum(A[right])) {
            right--;
        }
        if(tolower(A[left]) != tolower(A[right])) {
            return 0;
        }
        
        left++;
        right--;
    }
    
    return 1;
}
