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

void list_print(ListNode *head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

// Time - O(L), Space - O(L)
// where L is the length of the longer list
ListNode *solve(ListNode *A, ListNode *B) {
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

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    // 1 -> 2 -> 9
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(9);
    list_print(list1);
    // 1 -> 2 -> 9
    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(2);
    list2->next->next = new ListNode(9);
    list_print(list2);

    // Solution - 2 -> 4 -> 8 -> 1
    ListNode *sum_list = solve(list1, list2);
    list_print(sum_list);

    return 0;
}
