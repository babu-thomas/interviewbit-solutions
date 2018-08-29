/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Time - O(N), Space - O(1)
TreeNode* Solution::flatten(TreeNode* A) {
    if(A == nullptr) {
        return A;
    }

    TreeNode *node = A;
    while(node != nullptr) {
        if(node->left != nullptr) {
            TreeNode *rightmost = node->left;
            while(rightmost->right != nullptr) {
                rightmost = rightmost->right;
            }
            rightmost->right = node->right;

            node->right = node->left;
            node->left = nullptr;
        }

        node = node->right;
    }

    return A;
}
