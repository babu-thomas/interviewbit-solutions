/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int rec(TreeNode *root, int &result) {
    if(root == nullptr) {
        return 0;
    }

    int left = rec(root->left, result);
    int right = rec(root->right, result);

    int max_single = max(max(left, right) + root->val, root->val);
    int max_top = max(max_single, left + right + root->val);

    result = max(max_top, result);

    return max_single;
}

// Time - O(N), Space - O(N)
int Solution::maxPathSum(TreeNode* A) {
    int result = INT_MIN;
    rec(A, result);

    return result;
}
