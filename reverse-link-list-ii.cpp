/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Reverse n nodes of the list, returns the head of the new list.
ListNode* reverse_n(ListNode* head, int n) {
    ListNode *prev = head;
    ListNode *cur = prev->next;
    
    int count = 2;
    while(count <= n) {
        ListNode *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        count++;
    }
    
    head->next = cur;
    
    return prev;
}

// Time - O(N), Space - O(1)
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(B == C || A == nullptr) {
        return A;
    }
    
    ListNode *dummy = new ListNode(-1);
    dummy->next = A;
    ListNode *before_start = dummy;
    int count = 0;
    while(count < B - 1) {
        before_start = before_start->next;
        count++;
    }
    
    ListNode *new_start = reverse_n(before_start->next, C - B + 1);
    before_start->next = new_start;
    
    return dummy->next;
}
