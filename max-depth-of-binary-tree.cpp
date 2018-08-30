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
int max_depth(TreeNode *root) {
    if(root == nullptr) {
        return 0;
    }

    return 1 + max(max_depth(root->left), max_depth(root->right));
}

int Solution::maxDepth(TreeNode* A) {
    return max_depth(A);
}
