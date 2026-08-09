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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return NULL;

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *s = dummy;
        ListNode *f = head;

        while(f && f->next){
            s = s->next;
            f = f->next->next;
        }

        ListNode *temp = s->next;
        s->next = s->next->next;
        delete temp;

        delete dummy;

        return head;
    }
};