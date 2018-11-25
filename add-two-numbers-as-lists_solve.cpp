/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Time - O(L), Space - O(L)
// where L is the length of the longer list
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode *list1 = A;
    ListNode *list2 = B;

    if (!list1) {
        return list2;
    }
    if (!list2) {
        return list1;
    }

    int sum = 0, carry = 0;
    sum = list1->val + list2->val + carry;
    ListNode *cur_sum_digit = new ListNode(sum % 10);
    ListNode *sum_list_head = cur_sum_digit;
    carry = sum / 10;
    list1 = list1->next;
    list2 = list2->next;
    while (list1 || list2 || carry) {
        sum = (list1 ? list1->val : 0) + (list2 ? list2->val : 0) + carry;
        cur_sum_digit->next = new ListNode(sum % 10);
        carry = sum / 10;

        cur_sum_digit = cur_sum_digit->next;
        if (list1) {
            list1 = list1->next;
        }
        if (list2) {
            list2 = list2->next;
        }
    }

    return sum_list_head;
}
