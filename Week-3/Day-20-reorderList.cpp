/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode *slow = head, *fast = head;
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast)    slow = slow->next;
        while(slow) {
            st.push(new ListNode(slow->val));
            slow = slow->next;
        }
        slow = head;    fast = head;
        while(fast and fast->next) {
            if(fast->next->next == NULL) {
                slow->next = NULL;
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        if(slow)    slow->next = NULL;
        slow = head;
        while(slow and !st.empty()) {
            ListNode* t = st.top();
            st.pop();
            t->next = slow->next;
            slow->next = t;
            slow = slow->next->next;
        }
    }
};
