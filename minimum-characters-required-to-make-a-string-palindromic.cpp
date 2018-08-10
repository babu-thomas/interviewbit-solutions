bool is_palindrome(const string& A)
{
    int n = A.size();
    int left = 0, right = n - 1;
    while(left < right) {
        if(A[left] != A[right]) {
            return false;
        }
        left++;
        right--;
    }
    
    return true;   
}

// Time - O(N^2), Space - O(1)

int Solution::solve(string A) {
    int count = 0;
    while(A.size() > 1) {
        if(is_palindrome(A)) {
            return count;
        }
        A.pop_back();
        count++;
    }
    
    return count;
}



// Time - O(N^2), Space - O(1)
// Similar idea as before. Find the length of the longest palindromic subarray
// starting from beginning of string. The required answer is the difference between
// this length and the string length.
int Solution::solve(string A) {
    int n = A.size();
    int left = 0, right = n - 1, cur_right = right;
    while(left < cur_right) {
        if(A[left] == A[cur_right]) {
            left++;
            cur_right--;
        }
        else {
            left = 0;
            right--;
            cur_right = right;
        }
    }
    
    return n - (right + 1);
}



// Time - O(N), Space - O(N)
// Approach - Use LSP array from KMP algorithm to find the matching characters in the string.
// The number of remaining characters need to be added to front and is the answer.
vector<int> compute_lps(const string& A)
{
    int n = A.size();
    vector<int> lps(n);
    lps[0] = 0;
    for(int i = 1; i < n; i++) {
        int j = lps[i - 1];
        while(j > 0 && A[i] != A[j]) {
            j = lps[j - 1];
        }
        if(A[i] == A[j]) {
            j++;
        }
        lps[i] = j;
    }
    
    return lps;
}

int Solution::solve(string A) {
    int n = A.size();
    string rev = A;
    reverse(rev.begin(), rev.end());
    string concat = A + "$" + rev;
    vector<int> lps = compute_lps(concat);
    int characters_matched = lps[lps.size() - 1];
    
    return n - characters_matched;
}
