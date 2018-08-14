/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Time - O(N), Space - O(1)
ListNode* Solution::reverseList(ListNode* A) {
    if(A == nullptr) {
        return A;
    }
    ListNode *first = A;
    ListNode *second = first->next;
    if(second == nullptr) {
        return A;
    }
    
    while(second != nullptr) {
        ListNode *third = second->next;
        second->next = first;
        first = second;
        second = third;
    }
    
    A->next = nullptr;
    
    return first;
}
