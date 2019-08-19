/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//暴力解，两重循环遍历headA和headB，时间复杂度m*n
class Solution {       
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp = headB;
        while(headA)
        {
            headB=temp;
            while(headB)
            {
                if(headA == headB)
                    return headA;
                headB = headB->next;
            }
            headA = headA->next;
        }
        return NULL;
        
    }
};
