int Solution::sqrt(int A) {
    if(A == 0 || A == 1) {
        return A;
    }
    int low = 0;
    int high = A / 2;
    long long result;
    while(low <= high) {
        long long mid = (low + high) / 2;
        long long square = mid * mid;
        if(square == A) {
            return mid;
        }
        else if(square < A) {
            low = mid + 1;
            result = mid;
        }
        else {
            high = mid - 1;
        }
    }
    
    return result;
}