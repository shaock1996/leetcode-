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



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//方法二，两指针相遇，时间复杂度n

int get_list_length(ListNode *head) //求列表长度
{
    int len = 0;
    while(head)
    {
        head = head->next;
        len++;
    }
    return len;
}

ListNode *head_move(int dealt,ListNode *head) //head指针右移dealt个位置
{
    while(head && dealt--)
    {
        head = head->next;
    }
    return head;
}


class Solution 
{       
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int len_A,len_B;
        ListNode *headA_move,*headB_move;
        len_A = get_list_length(headA);
        len_B = get_list_length(headB);
        if(len_A>len_B)
        {
            headA_move = head_move(len_A-len_B,headA);
            headB_move = headB;
            
        }
        if(len_A<=len_B)
        {
            headB_move = head_move(len_B-len_A,headB);
            headA_move = headA;
        }
        
        while(headA_move && headB_move)
        {
            if(headA_move == headB_move)
                return headA_move;
            headA_move = headA_move->next;
            headB_move = headB_move->next;
            
        }
        return NULL;
    }
};




//STL库中的set
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::set<ListNode*> node_set;
        while(headA)
        {
            node_set.insert(headA);
            headA = headA->next;
        }
        while(headB)
        {
            if (node_set.find(headB) != node_set.end())
                return headB;
            headB = headB->next;
        }
        return NULL;
    }
};
