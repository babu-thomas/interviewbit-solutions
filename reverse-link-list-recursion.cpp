/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Time - O(N), Space - O(N)
ListNode* rec(ListNode *head) {
    if(head->next == nullptr) {
        return head;
    }
    
    ListNode *new_head = rec(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head;
}

ListNode* Solution::reverseList(ListNode* A) {
    if(A == nullptr) {
        return A;
    }
    
    return rec(A);
}
