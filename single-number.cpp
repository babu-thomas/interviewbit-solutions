int xor_op(int first, int second) {
    return first ^ second;
}

int Solution::singleNumber(const vector<int> &A) {
    return accumulate(A.begin(), A.end(), 0, xor_op);
}
