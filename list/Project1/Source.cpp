#include<iostream>

struct Node 
{
	int val;
	Node* next;
	Node* prev;
};


class List
{
private:
	Node* head;
	Node* tail;
	int count;
public:
	List()
	{
		head = tail = NULL;
		count = 0;
	}
	List(const List& list)
	{
		head = tail = NULL;
		count = 0;

		Node* temp = list.head;
		while (temp != NULL)
		{
			AddToTail(temp->val);
			temp = temp->next;
		}
	}
	~List()
	{
		DelAllElem();
	}
	List& operator = (const List& list)
	{
		this -> ~List();
		Node* temp = list.head;
		while (temp != NULL)
		{
			AddToTail(temp->val);
			temp = temp->next;
		}
		return *this;
	}
	void AddToHead(int val)
	{
		Node* temp = new Node;

		temp->prev = NULL;
		temp->val = val;
		temp->next = head;

		if (head != 0)
		{
			head = temp;
		}
		if (count == 0)
		{
			head = tail = temp;
		}
		else
		{
			head = temp;
		}
		count++;
	}
	void AddToTail(int val)
	{
		Node* temp = new Node;

		temp->prev = tail;
		temp->val = val;
		temp->next = NULL;

		if (tail != 0)
		{
			tail->next = temp;
		}

		if (count == 0)
		{
			head = tail = temp;
		}
		else
		{
			tail = temp;
		}

		count++;
	}
	void DelHead()
	{
		Node* temp = new Node;

		if (head != NULL)
		{
			temp = head;
			temp = temp->next;
			head = temp;
			count--;
		}
	}
	void DelTail()
	{
		Node* temp = new Node;

		if (tail != NULL)
		{
			temp = tail;
			temp = temp->prev;
			temp->next = NULL;
			tail = temp;
			count--;
		}
	}
	int FirstElem()
	{
		int val;
		if (head != NULL)
		{
			val = head->val;
		}
		return val;
	}
	int LastElem()
	{
		int val;
		if (tail != NULL)
		{
			val = tail->val;
		}
		return val;
	}
	int LenList()
	{
		return count;
	}
	void ShowList()
	{
		Node* temp = new Node;
		temp = head;
		if (count != 0) {
			while (temp != NULL)
			{
				std::cout << temp->val << " ";
				temp = temp -> next;
			}
		}
	}
	void DelAllElem()
	{
		while (head != NULL)
		{
			head->prev = NULL;
			head = head->next;
			count--;
		}
	}
};

void swap(List& a, List& b)
{
	List c = a;
	a = b;
	b = c;
}

int main()
{
	int b = 10;
	List a;
	a.AddToHead(b);
	a.AddToHead(2);
	a.AddToTail(11);
	b = a.LastElem();
	b = a.LenList();
	a.ShowList();
	List c;
	c = a;
	c.AddToHead(4);
	std::cout << std::endl;
	c.ShowList();
	std::cout << std::endl;
	std::cout << std::endl;
	swap(a, c);
	a.ShowList();
	std::cout << std::endl;
	c.ShowList();
	std::cout << std::endl;
	std::cout << "b = " << b << std::endl;
	return 0;
}