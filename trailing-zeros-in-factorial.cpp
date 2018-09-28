int Solution::trailingZeroes(int A) {
    int result = 0;
    for(int i = 5; A / i > 0; i *= 5) {
        result += A / i;
    }

    return result;
}
