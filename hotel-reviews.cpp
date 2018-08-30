template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

#define ALPHABET_SIZE 26

struct TrieNode {
    array<TrieNode*, ALPHABET_SIZE> children;
    bool is_end_of_word;
    TrieNode() : children {}, is_end_of_word {} {
    }
};

// Time - O(K), Space - O(K)
// where K is the length of the longest key
void trie_insert(TrieNode *root, const string& key) {
    TrieNode *cur_node = root;
    for(int i = 0; i < key.size(); i++) {
        int index = key[i] - 'a';

        if(cur_node->children[index] == nullptr) {
            cur_node->children[index] = new TrieNode();
        }

        cur_node = cur_node->children[index];
    }

    cur_node->is_end_of_word = true;
}

// Time - O(K)
// where K is the length of the key
bool trie_is_present(TrieNode* root, const string& key) {
    TrieNode *cur_node = root;
    for(int i = 0; i < key.size(); i++) {
        int index = key[i] - 'a';
        if(cur_node->children[index] == nullptr) {
            return false;
        }
        cur_node = cur_node->children[index];
    }

    return cur_node->is_end_of_word;
}

vector<int> Solution::solve(string A, vector<string> &B) {
    vector<int> result;
    vector<string> keys = split(A, '_');
    TrieNode *trie_root = new TrieNode();
    for(auto& k: keys) {
        trie_insert(trie_root, k);
    }

    int n = B.size();
    vector<pair<int, int>> good_count(n);
    for(int i = 0; i < n; i++) {
        good_count[i].first = i;
        vector<string> review_words = split(B[i], '_');
        for(auto& word: review_words) {
            if(trie_is_present(trie_root, word)) {
                good_count[i].second++;
            }
        }
    }

    auto comp = [](const pair<int, int>& a, const pair<int, int>&b) { return a.second > b.second; };

    stable_sort(good_count.begin(), good_count.end(), comp);

    for(int i = 0; i < n; i++) {
        result.push_back(good_count[i].first);
    }

    return result;
}
