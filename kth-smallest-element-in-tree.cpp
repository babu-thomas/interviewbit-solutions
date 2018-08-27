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
void rec(TreeNode *root, int &cur_idx, int find_idx, int &result) {
    if(root == nullptr || cur_idx > find_idx) {
        return;
    }

    rec(root->left, cur_idx, find_idx, result);
    cur_idx++;
    if(cur_idx == find_idx) {
        result = root->val;
        return;
    }
    rec(root->right, cur_idx, find_idx, result);
}

int Solution::kthsmallest(TreeNode* A, int B) {
    int cur_idx = 0;
    int result = -1;
    rec(A, cur_idx, B, result);
    
    return result;
}
