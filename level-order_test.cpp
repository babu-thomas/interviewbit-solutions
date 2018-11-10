#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x)                                                               \
    do {                                                                       \
        std::cout << #x << ": " << x << " ";                                   \
    } while (0)
#define DEBUGL(x)                                                              \
    do {                                                                       \
        std::cout << #x << ": " << x << "\n";                                  \
    } while (0)

#define MOD 1000000007

template <typename T> void print_vector(vector<T> a) {
    for (auto &i : a) {
        cout << i << " ";
    }
    cout << "\n";
}

template <typename T> void print_matrix_2d(vector<vector<T>> a) {
    int r = 0;
    for (auto &i : a) {
        cout << r << ": ";
        for (auto &j : i) {
            cout << j << " ";
        }
        r++;
        cout << "\n";
    }
    cout << "\n";
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> solve(TreeNode *A) {
    TreeNode *root = A;

    vector<vector<int>> result;

    if (root == nullptr) {
        return result;
    }

    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        vector<int> level_nodes;
        int cur_level = q.front().second;
        while (!q.empty() && q.front().second == cur_level) {
            TreeNode *node = q.front().first;
            q.pop();
            level_nodes.push_back(node->val);
            if (node->left != nullptr) {
                q.push({node->left, cur_level + 1});
            }
            if (node->right != nullptr) {
                q.push({node->right, cur_level + 1});
            }
        }

        result.push_back(level_nodes);
    }

    return result;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = solve(root);

    print_matrix_2d(result);

    return 0;
}
