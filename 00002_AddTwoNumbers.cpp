// You are given two non - empty linked lists representing two non - negative integers.
// The digits are stored in reverse order, and each of their nodes contains a single digit.
// Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.


/* 
    To solve the problem I have created a loop which goes through elements as long as they are.  If the sum is greater than 9 I reduce it by 10, and make boolean addOne a value of true (1).
    I go through all elements and I am creating new, each time I have to add a new one. At the end I return a pointer to the initial value;
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool addOne = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int sum;
        while (l1 || l2 || addOne)
        {
            sum = addOne;
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            addOne = sum > 9;
            sum -= addOne * 10;

            current->next = new ListNode(sum);
            current = current->next;
        }
        return dummy->next;
    }
};