// Time - O(Log A), Space - O(1)
// where A = dividend
int Solution::divide(int A, int B) {
    int dividend = A;
    int divisor = B;
    
    if((divisor == 0) || (dividend == INT_MIN && divisor == -1)) {
        return INT_MAX;
    }

    bool is_negative = ((dividend < 0) ^ (divisor < 0));
    long long divisor_abs = labs(divisor);
    long long dividend_abs = labs(dividend);
    int result = 0;
    while(dividend_abs >= divisor_abs) {
        long long multiple = divisor_abs, multiplier = 1;
        while(dividend_abs >= (multiple << 1)) {
            multiple <<= 1;
            multiplier <<= 1;
        }
        dividend_abs -= multiple;
        result += multiplier;
    }

    if(is_negative) {
        return -result;
    }

    return result;
}
