/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool find_path(TreeNode *root, int to_find, vector<int>& path) {
    if(root == nullptr) {
        return false;
    }

    path.push_back(root->val);
    if(root->val == to_find) {
        return true;
    }

    bool left_path = root->left && find_path(root->left, to_find, path);
    bool right_path = root->right && find_path(root->right, to_find, path);

    if(left_path || right_path) {
        return true;
    }

    path.pop_back();

    return false;
}

// Time - O(N), Space - O(N)
int Solution::lca(TreeNode* A, int B, int C) {
    vector<int> path1, path2;
    
    if(!find_path(A, B, path1) || !find_path(A, C, path2)) {
        return -1;
    }

    int i;
    for(i = 0; i < path1.size() && i < path2.size(); i++) {
        if(path1[i] != path2[i]) {
            break;
        }
    }

    return path1[i - 1];
}
