/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Returns -1 if not balanced, else returns height of tree
int is_balanced(TreeNode *root) {
    if(root == nullptr) {
        return 0;
    }

    int left_height = is_balanced(root->left);
    int right_height = is_balanced(root->right);

    if(left_height != -1 && right_height != -1
        && abs(left_height - right_height) <= 1) {
        return max(left_height, right_height) + 1;
    }

    return -1;
}

// Time - O(N), Space - O(N)
int Solution::isBalanced(TreeNode* A) {
    int result = is_balanced(A);
    if(result == -1) {
        return 0;
    }
    
    return 1;
}
