int Solution::isPalindrome(int A) {
    if(A < 0) {
        return 0;
    }
    
    int number = A;
    int reverse = 0;
    while(number != 0) {
        reverse = reverse * 10 + (number % 10);
        number = number / 10;
    }
    
    return A == reverse ? 1 : 0;
}
