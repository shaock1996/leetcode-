/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode small(0);
        ListNode big(0);
        ListNode *ptr_small = &small;
        ListNode *ptr_big = &big;
        while(head)
        {
            if(head->val < x)
            {
                ptr_small->next = head;
                ptr_small = head;
            }
            else
            {
                ptr_big->next = head;
                ptr_big = head;
            }
            head = head->next;
        }
        ptr_small->next = big.next;
        ptr_big->next = NULL;
        return small.next;
    }
};
