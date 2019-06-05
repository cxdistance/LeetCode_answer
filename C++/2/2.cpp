#include<iostream>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	//	sample implementation 
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (!l1) return l2;
		if (!l2) return l1;
		ListNode *head = new ListNode(0);
		ListNode *node = head;
		int carry = 0;
		while (l1 || l2)
		{
			int a = l1 ? l1->val : 0;
			int b = l2 ? l2->val : 0;
			int sum = a + b + carry;
			node->next = new ListNode(sum % 10);
			carry = sum / 10;
			if (l1)
				l1 = l1->next;
			if (l2)
				l2 = l2->next;
			node = node->next;
		}
		if (carry)
			node->next = new ListNode(carry);
		node = head->next;
		delete head;
		return node;
	}
};
int main()
{
	ListNode * head1 = new ListNode(0);	//	test: 0 1 2 3 
	ListNode * head2 = new ListNode(5);	//	test: 5 6 7 8
	ListNode * node1 = head1;
	ListNode * node2 = head2;
	for (int i = 1; i < 4; i++)
	{
		node1->next = new ListNode(i);
		node2->next = new ListNode(i + 5);
		node1 = node1->next;
		node2 = node2->next;
	}
	Solution so;
	ListNode* head = so.addTwoNumbers(head1, head2);
	while (head != NULL)
	{
		std::cout << head->val;
		head = head->next;
	}
	return 0;
}
