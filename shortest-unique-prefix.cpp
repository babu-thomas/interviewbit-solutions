#define ALPHABET_SIZE 26

struct TrieNode {
    array<TrieNode*, ALPHABET_SIZE> children;
    bool is_end_of_word;
    int count;
    TrieNode() : children {}, is_end_of_word {}, count {} {
    }
};

void insert(TrieNode *root, const string& key) {
    TrieNode *cur_node = root;
    for(int i = 0; i < key.size(); i++) {
        int index = key[i] - 'a';

        if(cur_node->children[index] == nullptr) {
            cur_node->children[index] = new TrieNode();
        }
        cur_node = cur_node->children[index];
        cur_node->count++;
    }

    cur_node->is_end_of_word = true;
}

int unique_prefix_index(TrieNode* root, const string& key) {
    TrieNode *cur_node = root;
    for(int i = 0; i < key.size(); i++) {
        int child_idx = key[i] - 'a';
        cur_node = cur_node->children[child_idx];

        if(cur_node->count == 1) {
            return i;
        }
    }

    // Shouldn't reach here
    return key.size();
}

// Time - O(N), Space - O(K)
// where K is the length of the longest string in A
vector<string> Solution::prefix(vector<string> &A) {
    TrieNode *root = new TrieNode();
    for(auto& k : A) {
        insert(root, k);
    }

    vector<string> result;
    for(auto& k: A) {
        int idx = unique_prefix_index(root, k);
        result.push_back(k.substr(0, idx + 1));
    }

    return result;
}
