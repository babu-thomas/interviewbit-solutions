// Time - O(N), Space - O(N)
string Solution::addBinary(string A, string B) {
    int a_pos = A.size() - 1, b_pos = B.size() - 1, carry = 0;
    vector<char> result;
    
    while(a_pos >= 0 || b_pos >= 0 || carry != 0) {
        if(a_pos >= 0) carry += (A[a_pos] - '0');
        if(b_pos >= 0) carry += (B[b_pos] - '0');
        result.push_back((carry & 1) + '0');
        a_pos--;
        b_pos--;
        carry >>= 1;
    }
    
    return string(result.rbegin(), result.rend());
}
