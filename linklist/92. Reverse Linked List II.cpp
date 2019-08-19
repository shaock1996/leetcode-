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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int x = m;
        int change_len = n-m+1;
        ListNode* left = NULL;
        ListNode*result = head;
        while(head && --m)    //移动到要开始翻转的m位置
        {
            left = head;
            head = head->next;    
        }
        
        ListNode *new_tail = head;  //翻转并存储必要的变量
        ListNode *temp,*new_head=NULL;
        while(head && change_len-- )
        {
            temp = head->next;
            head->next = new_head;
            new_head = head;
            head = temp;   
        }
        new_tail->next = head;   //连接尾部
        
        //if(left)    //通过判断left是否为空确定返回值及是否需连接头部
        if(x!=1)              //也可通过m值是否为1判断,因为之前做了--m,所以m值都会变成0，如果这么判断之前需要一个临时变量来存储m值
        {
            left->next = new_head;
        }
        else result = new_head;
        return result;
       
    }
};
