//方法一，STL中set，时间慢且空间大，但直接易于理解
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
    bool hasCycle(ListNode *head) {
     std::set<ListNode*> node_set;
        while(head)
        {
            if(node_set.find(head) != node_set.end())
            {
                return true;
            }
            node_set.insert(head);
            head = head->next;
        }
        return false;
    }
};




//方法二，双指针，快且空间小，有一定技巧性
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
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast)
        {
            fast = fast->next;
            slow = slow->next;
            if (!fast)
            {
                return false;
            }
            fast = fast->next;
            if(fast == slow)
            {
                return true;
            }
        }
        return false;
    }
};
