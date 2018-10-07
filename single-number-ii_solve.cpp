// Time - O(N), Space - O(1)
int Solution::singleNumber(const vector<int> &A) {
    int n = A.size();
    int result = 0;

    // For every bit of an integer
    for(int num = INT_MAX, i = 0; num > 0; num >>= 1, i++) {
        int sum = 0;
        int check_bit = (1 << i);

        // Count how many elements have a set bit at current position
        for(int ele = 0; ele < n; ele++) {
            if(A[ele] & check_bit) {
                sum++;
            }
        }

        if(sum % 3 != 0) {
            result |= check_bit;
        }
    }

    return result;
}
