/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int is_bst(TreeNode *root, int min, int max) {
    if(root == nullptr) {
        return 1;
    }
 
    if(root->val < min || max < root->val) {
        return 0;
    }
 
    return is_bst(root->left, min, root->val - 1) &&
        is_bst(root->right, root->val + 1, max);
}
 
int Solution::isValidBST(TreeNode* A) {
    return is_bst(A, INT_MIN, INT_MAX);
}
