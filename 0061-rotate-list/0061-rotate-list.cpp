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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;

        int n = 0; // ll size

        ListNode *temp = head;

        while(temp){
            n++;
            temp = temp->next;
        }

        k = k % n;

        if(k == 0) return head;

        ListNode *tail = head;
        while(k--){
            tail = tail->next;
        }

        ListNode *curr = head;
        while(tail->next){
            curr = curr->next;
            tail = tail->next;
        }

        tail->next = head;
        ListNode *newHead = curr->next;

        curr->next = NULL;

        return newHead;
    }
};