#pragma once
template<typename Elemtype>
class List
{
private:
	struct ListNode
	{
		Elemtype val;
		ListNode* next;
	}*LNode;
public:
	List()
	{
		LNode = new ListNode;
		LNode->next = nullptr;
	}
	void CreateList_R(int num)
	{
		ListNode *L = LNode;
		cin >> L->val;
	
		for (int j = 0; j < num; j++)
		{   
			ListNode *P = new ListNode;
			cin >> P->val;
			L->next = P->next;
			L = P;

		}
	}
	void CreateList_L(int n)
	{
		ListNode *L = LNode;
		cin >> L->val;
		for (int j = 0; j < n; j++)
		{
			ListNode *P = new ListNode;
			cin >> P->val;
			P->next = nullptr;
			L->next = P;
			L = P;

		}
	}
	void Traversal_Array()
	{
		ListNode *L = LNode;
		while (1)
		{
			if (L->next == nullptr)
			{
				cout << L->val;
				break;
			}
				
			else
			{
				cout << L->val << endl;
				L = L->next;
			}
		}
	}
	

};
