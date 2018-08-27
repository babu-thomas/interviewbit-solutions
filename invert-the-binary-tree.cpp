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
void invert_binary_tree(TreeNode *root) {
    if(root == nullptr) {
        return;
    }
    
    swap(root->left, root->right);
    invert_binary_tree(root->left);
    invert_binary_tree(root->right);
    
    return;
}

TreeNode* Solution::invertTree(TreeNode* A) {
    invert_binary_tree(A);
    return A;
}
