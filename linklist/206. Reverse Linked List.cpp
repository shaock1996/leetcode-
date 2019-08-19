/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val; //值
 *     ListNode *next; //指向ListNode类型的指针
 *     ListNode(int x) : val(x), next(NULL) {}  //可用此函数创建并初始化一个链表节点，如ListNode a(10)
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = NULL;   //new_head初始化为NULL,作为翻转后尾结点
        ListNode* next;              //next指针用于存储head指向的下一个节点
        while(head)
        {
            next = head->next;         
            head->next = new_head;
            new_head = head;
            head = next;    
        }
        return new_head;
    }
};
