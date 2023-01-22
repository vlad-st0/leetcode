/** 2. Add Two Numbers */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        auto *result = new ListNode(0);
        auto *head = result;
        int carry = 0;

        while (l1 || l2)
        {
            const int num = getValAndNext(l1) + getValAndNext(l2) + carry;
            head->next = new ListNode(num % 10);
            head = head->next;
            carry = num / 10;
        }
        if (carry != 0)
            head->next = new ListNode(carry);

        return result->next;
    }

    int getValAndNext(ListNode *&l)
    {
        int x = 0;
        if (l != nullptr)
        {
            x = l->val;
            l = l->next;
        }
        return x;
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