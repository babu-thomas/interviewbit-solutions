// Time - O(N * M), Space - O(M)
// where N = number of strings, M = length of shortest string
string Solution::longestCommonPrefix(vector<string> &A) {
    int n = A.size();
    string result;
    
    auto compare = [](const string& a, const string& b) {
        return a.size() < b.size();
    };
    
    int min_len = (*min_element(A.begin(), A.end(), compare)).size();

    for(int i = 0; i < min_len; i++) {
        char current = A[0][i];

        for(int j = 0; j < n; j++) {
            if(A[j][i] != current) {
                return result;
            }
        }

        result.push_back(current);
    }

    return result;
}
