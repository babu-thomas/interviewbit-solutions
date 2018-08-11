vector<int> int_to_vec(int num)
{
    vector<int> result;
    while(num != 0) {
        result.push_back(num % 10);
        num = num / 10;
    }
    if(result.size() == 0) {
        result.push_back(0);
    }
    reverse(result.begin(), result.end());
    return result;
}

int rec(const vector<int>& A, int B, const vector<int>& C, int pos)
{
    if(B == 0) {
        return 0;
    }
    
    int n = A.size();
    int i, count = 0;
    for(i = 0; i < n; i++) {
        if(A[i] >= C[pos]) {
            break;
        }
        count++;
    }
    
    if(pos == 0 && A[0] == 0) {
        count--;
    }
    
    int result = count * pow(n, B - 1);
    
    if(i == n || A[i] != C[pos]) {
        return result;
    }
    
    return result + rec(A, B - 1, C, pos + 1);
}

int Solution::solve(vector<int> &A, int B, int C) {
    int n = A.size();
    vector<int> c_digits = int_to_vec(C);
    int c_n = c_digits.size();
    // Case 1
    if(B > c_n || n == 0) {
        return 0;
    }

    // Case 2
    if(B < c_n) {
        if(A[0] == 0 && B > 1) {
            return (n - 1) * pow(n, B - 1);
        }

        return pow(n, B);
    }

    // Case 3
    return rec(A, B, c_digits, 0);
}
