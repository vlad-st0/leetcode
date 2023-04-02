#include <vector>

using std::vector;

/** Definition for singly-linked list. */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/** 19. Remove Nth Node From End of List */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        auto *pacer = head, *pacer2 = head;
        int size = 0;
        while (pacer->next)
        {
            size++;
            pacer = pacer->next;
        }
        if (n == size)
            return head->next;
        for (int i = 0; i < size - n; i++)
            pacer2 = pacer2->next;
        pacer2->next = pacer2->next ? pacer2->next->next : nullptr;
        return head;
    }
};