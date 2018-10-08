unsigned int Solution::reverse(unsigned int A) {
    uint32_t result = 0;
    for(int i = 0; i < 32; i++, A >>= 1) {
        result <<= 1;
        result |= (A & 1);
    }

    return result;
}
