/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct Compare {
    bool operator()(ListNode* const& a, ListNode* const& b) {
        return a->val > b->val;
    }
};

// Time - O(N LogK), Space - O(K)
// where N = total elements in all lists, K = number of lists
ListNode* solve(vector<ListNode*> &lists) {
    if(lists.empty()) {
        return nullptr;
    }
    
    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;

    priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

    for(auto& list: lists) {
        if(list != nullptr) {
            pq.emplace(list);
        }
    }

    while(!pq.empty()) {
        tail->next = pq.top();
        pq.pop();
        tail = tail->next;
        if(tail->next != nullptr) {
            pq.emplace(tail->next);
        }
    }

    return dummy->next;
}

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    return solve(A);
}
