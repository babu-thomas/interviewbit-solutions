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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> result;
    
    if(A == nullptr) {
        return result;
    }

    queue<pair<TreeNode*, int>> q;
    q.push({A, 0});
    while(!q.empty()) {
        vector<int> level_nodes;
        int cur_level = q.front().second;
        while(!q.empty() && q.front().second == cur_level) {
            TreeNode *node = q.front().first;
            q.pop();
            level_nodes.push_back(node->val);
            if(node->left != nullptr) {
                q.push({node->left, cur_level + 1});
            }
            if(node->right != nullptr) {
                q.push({node->right, cur_level + 1});
            }
        }

        if(cur_level % 2 == 0) {
            result.push_back(level_nodes);
        }
        else {
            reverse(level_nodes.begin(), level_nodes.end());
            result.push_back(level_nodes);
        }
    }

    return result;
}
