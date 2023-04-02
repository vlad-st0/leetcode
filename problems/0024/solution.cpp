/** Definition for singly-linked list. */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/** 24. Swap Nodes in Pairs */
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        auto *result = new ListNode();
        auto *prevNode = result;
        auto *currNode = head;

        while (currNode && currNode->next)
        {
            prevNode->next = currNode->next;
            currNode->next = prevNode->next->next;
            prevNode->next->next = currNode;

            prevNode = currNode;
            currNode = currNode->next;
        }

        return result->next;
    }
};