// Time - O(N), Space - O(N + M)
// where N = size of text, M = size of pattern
string solve(const string& text, const string& pattern) {
    int t_size = text.size();
    int p_size = pattern.size();

    if(p_size > t_size) {
        return "";
    }

    // Store counts of characters in pattern
    unordered_map<char, int> p_count;
    for(auto& c: pattern) {
        p_count[c]++;
    }

    // Store counts of characters in text
    unordered_map<char, int> t_count;
    int cur_start = 0, min_start = -1, min_len = INT_MAX, found_chars = 0;
    for(int i = 0; i < t_size; i++) {
        char cur_char = text[i];
        // Update count of characters in text
        t_count[cur_char]++;

        // Update count of found characters
        if(p_count[cur_char] != 0 && t_count[cur_char] <= p_count[cur_char]) {
            found_chars++;
        }

        if(found_chars != p_size) {
            continue;
        }

        // If we have found all the characters in pattern, keep incrementing start while there
        // are extra characters, to minimize the window length
        char sub_beg = text[cur_start];
        while(t_count[sub_beg] > p_count[sub_beg]) {
            t_count[sub_beg]--;
            cur_start++;
            sub_beg = text[cur_start];
        }

        int cur_len = i - cur_start + 1;
        if(min_len > cur_len) {
            min_len = cur_len;
            min_start = cur_start;
        }
    }

    if(min_start == -1) {
        return "";
    }

    return text.substr(min_start, min_len);
}

string Solution::minWindow(string A, string B) {
    return solve(A, B);
}
