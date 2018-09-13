// Time - O(N^3), Space - O(N^2)
// where N = size of sentence
vector<string> rec(const string& sentence, const vector<string>& dict,
    unordered_map<string, vector<string>>& found) {
    
    if(found.count(sentence)) {
        return found[sentence];
    }

    int n = sentence.size();
    vector<string> result;
    for(int i = 1; i <= n; i++) {
        string word = sentence.substr(0, i);
        string rem = sentence.substr(i);
        if(find(dict.begin(), dict.end(), word) != dict.end()) {
            if(rem.empty()) {
                result.push_back(word);
            }
            else {
                for(auto& s: rec(rem, dict, found)) {
                    result.push_back(word + " " + s);
                }
            }
        }
    }

    found[sentence] = result;
    return result;
}

vector<string> Solution::wordBreak(string A, vector<string> &B) {
    unordered_map<string, vector<string>> found;
    return rec(A, B, found);
}
