class Solution
{
public:
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        if(!l1 || !l2) return l1?l1:l2;
        if(l1->val<=l2->val)
        {
            l1->next=merge(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next=merge(l1,l2->next);
            return l2;
        }
    }
    ListNode* sortList(ListNode* head)
    {
        if(head==nullptr || head->next == nullptr) return head;
        ListNode *slow = head,*fast = head, *temp = nullptr;
        while(fast && fast->next)
        {
            temp = slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next = nullptr;
        ListNode *left = sortList(head);
        ListNode *right = sortList(slow);
        return merge(left,right);
    }
};
