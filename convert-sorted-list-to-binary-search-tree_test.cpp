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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorder_traversal(TreeNode *root) {
    vector<int> result;

    if (root == nullptr) {
        return result;
    }

    stack<pair<TreeNode *, int>> node_states;
    node_states.push({root, 0});
    while (!node_states.empty()) {
        TreeNode *node = node_states.top().first;
        int cur_state = node_states.top().second;
        node_states.pop();

        if (node == nullptr || cur_state == 3) {
            continue;
        }

        node_states.push({node, cur_state + 1});

        if (cur_state == 0) {
            node_states.push({node->left, 0});
        } else if (cur_state == 1) {
            result.push_back(node->val);
        } else if (cur_state == 2) {
            node_states.push({node->right, 0});
        }
    }

    return result;
}

void list_print(ListNode *head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

int list_length(ListNode *head) {
    ListNode *i = head;
    int count = 0;
    while (i != nullptr) {
        count++;
        i = i->next;
    }
    return count;
}

TreeNode *list_to_balanced_bst(ListNode **list_head_ptr, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;

    TreeNode *left = list_to_balanced_bst(list_head_ptr, start, mid - 1);
    ListNode *list_head = *list_head_ptr;
    TreeNode *cur_tree_node = new TreeNode(list_head->val);
    *list_head_ptr = list_head->next;
    TreeNode *right = list_to_balanced_bst(list_head_ptr, mid + 1, end);

    cur_tree_node->left = left;
    cur_tree_node->right = right;

    return cur_tree_node;
}

// Time - O(N), Space - O(LogN)
TreeNode *solve(ListNode *A) {
    ListNode *list_head = A;

    int len = list_length(list_head);
    return list_to_balanced_bst(&list_head, 0, len - 1);
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    vector<int> nums = {-10, -1, 5, 64, 77, 100};

    ListNode *list_head = new ListNode(nums[0]);
    ListNode *cur_list_node = list_head;
    for (int i = 1; i < nums.size(); i++) {
        cur_list_node->next = new ListNode(nums[i]);
        cur_list_node = cur_list_node->next;
    }

    list_print(list_head);
    TreeNode *tree_root = solve(list_head);
    print_vector(inorder_traversal(tree_root));

    return 0;
}
