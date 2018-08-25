/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* search_node(TreeNode *root, int value) {
    if(root->val == value) {
        return root;
    }
    
    if(value < root->val) {
        return search_node(root->left, value);
    }

    return search_node(root->right, value);

}

// Time - O(logN), Space - O(1)
TreeNode* inorder_successor_of(TreeNode *root, TreeNode *node) {
    TreeNode *cur_root = root;
    TreeNode *succ = nullptr;
    while(cur_root != nullptr) {
        if(node->val < cur_root->val) {
            succ = cur_root;
            cur_root = cur_root->left;
        }
        else {
            cur_root = cur_root->right;
        }
    }

    return succ;
}

TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    TreeNode *node = search_node(A, B);
    return inorder_successor_of(A, node);
}
