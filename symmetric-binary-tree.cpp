/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int is_symmetric(TreeNode *left_root, TreeNode *right_root) {
    if(left_root == nullptr && right_root == nullptr) {
        return 1;
    }

    if(left_root == nullptr || right_root == nullptr) {
        return 0;
    }

    if(left_root->val != right_root->val) {
        return 0;
    }

    return is_symmetric(left_root->left, right_root->right) &&
        is_symmetric(left_root->right, right_root->left);

}

int Solution::isSymmetric(TreeNode* A) {
    if(A == nullptr) {
        return 1;
    }

    return is_symmetric(A->left, A->right);
}
