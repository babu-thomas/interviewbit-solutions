/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Time - O(N), Space - O(N)
TreeNode* Solution::buildTree(vector<int> &A) {
    TreeNode *root = nullptr;
    stack<TreeNode*> s;
    for(int i = 0; i < A.size(); i++) {
        TreeNode *last_removed = nullptr;
        while(!s.empty() && s.top()->val < A[i]) {
            last_removed = s.top();
            s.pop();
        }
        TreeNode *node = new TreeNode(A[i]);
        node->left = last_removed;
        if(s.empty()) {
            root = node;
        }
        else {
            s.top()->right = node;
        }
        s.push(node);
    }

    return root;
}



// Time - O(N^2), Space - O(N)
TreeNode* rec(const vector<int>& nodes, int start, int end) {
    if(start >= end) {
        return nullptr;
    }

    if(start == end - 1) {
        TreeNode *node = new TreeNode(nodes[start]);
        return node;
    }

    auto max_it = max_element(nodes.begin() + start, nodes.begin() + end);
    TreeNode *root = new TreeNode(*max_it);
    int max_idx = distance(nodes.begin(), max_it);
    root->left = rec(nodes, start, max_idx);
    root->right = rec(nodes, max_idx + 1, end);
    return root;
}

TreeNode* Solution::buildTree(vector<int> &A) {
    int start = 0;
    int end = A.size();
    return rec(A, start, end);
}
