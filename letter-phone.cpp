// BFS
using LetterMap = unordered_map<char, string>;

vector<string> Solution::letterCombinations(string A) {
    vector<string> result;
    int n = A.size();
    if(n == 0) {
        return result;
    }
    
    LetterMap letters = {
        {'1', "1"}, {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
        {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}, {'0', "0"}
    };
    
    queue<string> q;
    q.push("");
    for(int i = 0; i < n; i++) {
        while(q.front().size() == i) {
            string partial = q.front();
            q.pop();
            for(auto& c: letters[A[i]]) {
                q.push(partial + c);
            }
        }
    }
    
    while(!q.empty()) {
        result.push_back(q.front());
        q.pop();
    }
    
    return result;
}


// DFS
using LetterMap = unordered_map<char, string>;

void rec(const string& A, LetterMap& letters, int pos, string& current,
    vector<string>& result) {
        
    if(pos == A.size()) {
        result.push_back(current);
        return;
    }
    
    for(auto& c: letters[A[pos]]) {
        current.push_back(c);
        rec(A, letters, pos + 1, current, result);
        current.pop_back();
    }
}

vector<string> Solution::letterCombinations(string A) {
    vector<string> result;
    int n = A.size();
    if(n == 0) {
        return result;
    }
    
    LetterMap letters = {
        {'1', "1"}, {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
        {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}, {'0', "0"}
    };
    
    string current;
    rec(A, letters, 0, current, result);
    
    return result;
}
