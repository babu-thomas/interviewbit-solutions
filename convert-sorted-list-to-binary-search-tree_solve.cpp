/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

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
TreeNode* Solution::sortedListToBST(ListNode* A) {
    ListNode *list_head = A;

    int len = list_length(list_head);
    return list_to_balanced_bst(&list_head, 0, len - 1);
}
