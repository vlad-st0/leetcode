/** 21. Merge Two Sorted Lists */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        ListNode *result, *last;

        if (list1->val < list2->val)
        {
            result = last = list1;
            list1 = list1->next;
        }
        else
        {
            result = last = list2;
            list2 = list2->next;
        }

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                last->next = list1;
                list1 = list1->next;
            }
            else
            {
                last->next = list2;
                list2 = list2->next;
            }
            last = last->next;
        }

        last->next = list1 ? list1 : list2;

        return result;
    }
};

/** Definition for singly-linked list. */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};