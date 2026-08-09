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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *p1 = head;

        while(n > 0){
            p1 = p1->next;
            n--;
        }

        if(p1 == NULL){
            ListNode * temp = head;
            head = head->next;

            delete temp;
            return head;
        }

        ListNode *p2 = head;
        while(p1->next){
            p1 = p1->next;
            p2 = p2->next;
        }

        ListNode *toDelete = p2->next;
        p2->next = p2->next->next;

        delete toDelete;

        return head;
    }
};