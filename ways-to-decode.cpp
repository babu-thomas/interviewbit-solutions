bool is_valid(int num) {
    return 0 < num && num <= 26;
}

int rec(const string& code, vector<int>& found, int start_idx) {
    int n = code.size();
    if(start_idx == n) {
        return 1;
    }
    if(!is_valid(code[start_idx] - '0')) {
        return 0;
    }

    if(found[start_idx] != -1) {
        return found[start_idx];
    }

    int result = 0;
    result += rec(code, found, start_idx + 1);

    if(start_idx < n - 1) {
        int num = (code[start_idx] - '0') * 10 + (code[start_idx + 1] - '0');
        if(is_valid(num)) {
            result += rec(code, found, start_idx + 2);
        }
    }

    found[start_idx] = result;
    return result;
}

// Time - O(N), Space - O(N)
int Solution::numDecodings(string A) {
    int n = A.size();

    if(n == 0) {
        return 0;
    }
    
    vector<int> found(n, -1);
    return rec(A, found, 0);
}
