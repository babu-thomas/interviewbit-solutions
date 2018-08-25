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
// The idea is to traverse the tree in level order and store the nodes at a particular
// horizontal distance from root in a map. As we also keep track of the min and
// max horizontal distance, we can use unordered_map having O(1) insertion.
vector<vector<int>> vertical_order_traversal(TreeNode *root) {
    vector<vector<int>> result;
    
    if(root == nullptr) {
        return result;
    }

    queue<pair<TreeNode*, int>> level_nodes;
    int h_dist = 0, min_dist = INT_MAX, max_dist = INT_MIN;
    level_nodes.push({root, h_dist});

    unordered_map<int, vector<int>> vertical_nodes;

    while(!level_nodes.empty()) {
        TreeNode *node = level_nodes.front().first;
        h_dist = level_nodes.front().second;
        min_dist = min(h_dist, min_dist);
        max_dist = max(h_dist, max_dist);
        level_nodes.pop();
        vertical_nodes[h_dist].push_back(node->val);
        
        if(node->left) {
            level_nodes.push({node->left, h_dist - 1});
        }
        if(node->right) {
            level_nodes.push({node->right, h_dist + 1});
        }
    }

    for(int i = min_dist; i <= max_dist; i++) {
        if(vertical_nodes.count(i)) {
            result.push_back(vertical_nodes[i]);
        }
    }

    return result;
}

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    return vertical_order_traversal(A);
}
