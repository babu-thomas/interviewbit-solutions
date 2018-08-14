/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int list_length(ListNode* A) {
    ListNode* i = A;
    int count = 0;
    while(i != nullptr) {
        count++;
        i = i -> next;
    }
    return count;
}

// Time - O(N), Space - O(1)
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    int a_len = list_length(A);
    int b_len = list_length(B);
    
    int diff = a_len - b_len;
    ListNode *long_list = A;
    ListNode *short_list = B;
    
    if(diff < 0) {
        diff *= -1;
        long_list = B;
        short_list = A;
    }
    
    for(int i = 0; i < diff; i++) {
        long_list = long_list->next;
    }
    
    while(short_list != nullptr && long_list != nullptr) {
        if(short_list == long_list) {
            return short_list;
        }
        short_list = short_list->next;
        long_list = long_list->next;
    }
    
    return nullptr;
}
