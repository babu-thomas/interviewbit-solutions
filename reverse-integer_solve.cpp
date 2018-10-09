// Time - O(Log N), Space - O(1)
int Solution::reverse(int A) {
    long long result = 0;
    while(A != 0) {
        result = result * 10 + (A % 10);
        A /= 10;
    }

    if(result > INT_MAX || result < INT_MIN) {
        return 0;
    }
    
    return result;
}
