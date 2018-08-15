/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Inserts the node after before_val to the position after before_pos
void insert_after(ListNode *before_pos, ListNode *before_val) {
    ListNode *node = before_val->next;
    before_val->next = before_val->next->next;
    node->next = before_pos->next;
    before_pos->next = node;
}

// Time - O(N), Space - O(1)
ListNode* Solution::partition(ListNode* A, int B) {
    if(A == nullptr || A->next == nullptr) {
        return A;
    }
    
    ListNode *dummy = new ListNode(-1);
    dummy->next = A;
    
    ListNode *before_pos = dummy, *i;
    
    while(before_pos->next != nullptr && before_pos->next->val < B) {
        before_pos = before_pos->next;
    }
    
    i = before_pos;
    
    while(i->next != nullptr) {
        if(i->next->val < B) {
            insert_after(before_pos, i);
            before_pos = before_pos->next;
            continue;
        }
        
        i = i->next;
        if(i == nullptr) {
            break;
        }
    }
    
    return dummy->next;
}
