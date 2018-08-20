vector<int> solve(const string& text, const vector<string>& words) {
    vector<int> result;
    int text_size = text.size();
    int word_count = words.size();

    if(text_size == 0 || word_count == 0) {
        return result;
    }

    int word_size = words[0].size();
    int all_words_size = word_count * word_size;
    if(text_size < all_words_size) {
        return result;
    }

    unordered_map<string, int> words_present;
    for(auto& i: words) {
        words_present[i]++;
    }

    for(int i = 0; i <= text_size - all_words_size; i++) {
        unordered_map<string, int> substring_words(words_present);
        int j = i;
        while(j < i + all_words_size) {
            string word = text.substr(j, word_size);
            if(words_present.count(word)) {
                substring_words[word]--;
            }

            j += word_size;
        }
        bool found = true;
        for(auto& w: substring_words) {
            if(w.second > 0) {
                found = false;
                break;
            }
        }

        if(found) {
            result.push_back(i);
        }
    }

    return result;
}

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    return solve(A, B);
}
