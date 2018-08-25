/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> preorder_traversal(TreeNode *root) {
    vector<int> result;
    
    if(root == nullptr) {
        return result;
    }

    stack<pair<TreeNode*, int>> node_states;
    node_states.push({root, 0});
    while(!node_states.empty()) {
        TreeNode *node = node_states.top().first;
        int cur_state = node_states.top().second;
        node_states.pop();

        if(node == nullptr || cur_state == 3) {
            continue;
        }

        node_states.push({node, cur_state + 1});

        if(cur_state == 0) {
            result.push_back(node->val);
        }
        else if(cur_state == 1) {
            node_states.push({node->left, 0});
        }
        else if(cur_state == 2) {
            node_states.push({node->right, 0});
        }
    }

    return result;
}

vector<int> Solution::preorderTraversal(TreeNode* A) {
    return preorder_traversal(A);
}
