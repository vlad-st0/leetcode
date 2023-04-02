#include <vector>
#include <iostream>

using std::cout;
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

/** 25. Reverse Nodes in k-Group */
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head)
            return head;

        ListNode *temp = head;
        for (int i = 0; i < k; i++)
        {
            if (!temp)
                return head; // not enough elements to reverse
            temp = temp->next;
        }

        ListNode *next, *prev;
        ListNode *curr = head;
        int rep = 0;
        while (rep < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            rep++;
        }
        head->next = reverseKGroup(next, k);
        return prev;
    }
};

int main()
{
    auto l = new ListNode(1);
    auto ll = l;
    ll->next = new ListNode(2);
    ll = ll->next;
    ll->next = new ListNode(3);
    ll = ll->next;
    ll->next = new ListNode(4);
    ll = ll->next;
    ll->next = new ListNode(5);
    ll = ll->next;
    ll->next = new ListNode(6);
    ll = ll->next;
    ll->next = new ListNode(7);

    auto sol = new Solution();
    auto out = sol->reverseKGroup(l, 4);

    while (out)
    {
        cout << out->val << ' ';
        out = out->next;
    }
    cout << '\n';

    return 0;
}

// prevNode->next = currNode->next;
// currNode->next = prevNode->next->next;
// prevNode->next->next = currNode;

// prevNode = currNode;
// currNode = currNode->next;