/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Reverse n nodes of the list, returns the head of the new list.
// Also stores the nth node's address in the third parameter
ListNode* reverse_n(ListNode* head, int n, ListNode** last) {
    if(head == nullptr) {
        *last = nullptr;
        return head;
    }
    ListNode *prev = head;
    ListNode *cur = prev->next;
    if(cur == nullptr) {
        *last = prev;
        return head;
    }
    
    int count = 2;
    while(count <= n) {
        ListNode *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        count++;
    }
    
    head->next = cur;
    *last = head;
    
    return prev;
}

// Time - O(N), Space - O(1)
ListNode* Solution::reverseList(ListNode* A, int B) {
    if(B == 1) {
        return A;
    }
    
    ListNode *last = nullptr;
    ListNode *new_head = reverse_n(A, B, &last);
    
    while(last != nullptr) {
        ListNode* prev_last = last;
        ListNode* next_head = reverse_n(last->next, B, &last);
        prev_last->next = next_head;
    }
    
    return new_head;
}
