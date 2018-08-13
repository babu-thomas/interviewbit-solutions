// Time - O(N), Space - O(1)
int Solution::numSetBits(unsigned int A) {
    unsigned int count = 0;
    while(A) {
        A = A & (A - 1);
        count++;
    }
    
    return count;
}
