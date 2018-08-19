// Time - O(N), Space - O(S) where S is size of alphabet
int Solution::lengthOfLongestSubstring(string A) {
    int n = A.size();
    unordered_map<char, int> seen;
    int start = 0, end, max_len = 0;
    for(end = 0; end < n; end++) {
        if(seen.count(A[end])) {
            start = max(seen[A[end]] + 1, start);
        }
        
        max_len = max(max_len, end - start + 1);
        seen[A[end]] = end;
    }
    
    return max_len;
}
