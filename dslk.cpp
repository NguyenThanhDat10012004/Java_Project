#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node* next;
		
};


struct LinkedList
{
	Node* head;
	Node* tail;
	LinkedList()
	{
		head = NULL;
		tail = NULL;
	}
};



Node* Makenode(int x)
{
	Node* Newnode = new Node();
	Newnode->data = x;
	Newnode->next = NULL;
	return Newnode;
}

int count(LinkedList l)
{
	int dem = 1;
	Node *node = l.head;
	while(node -> next != NULL)
	{
		dem++;
		node = node -> next;
	}
	return dem;
}
void push_front(LinkedList &l, Node *node)
{
	if(l.head == NULL)
	{
		l.head = node;
		l.tail = node;
	}
	else
	{
		node -> next = l.head;
		l.head = node;
	}
}
void push_back(LinkedList &l, Node *node)
{
	if(l.head == NULL)
	{
		l.head = node;
		l.tail = node;
	}
	else
	{
		l.tail -> next = node;
		l.tail = node;
	}
}
void push_k(LinkedList &l, Node *node, int k)
{
	int n = count(l);
	if(k < 1 || k > n + 1) return;
	else if(k == 1) push_front(l, node);
	else if(k == n + 1) push_back(l, node);
	else
	{
		Node *Newnode = l.head;
		for(int i = 0; i < k - 2; i++)
		{
			Newnode = Newnode -> next;
		}
		node -> next = Newnode -> next;
		Newnode -> next = node;
	}
}
void delete_front(LinkedList &l)
{
	if(l.head == NULL) return;
	Node *node = l.head ;
	l.head = node -> next;
	delete node;
}
void delete_back(LinkedList &l)
{
	if(l.head == NULL)
	{
		return;
	}
	Node *node = l.head;
	while((node -> next) -> next)
	{
		node = node -> next;
	}
	node -> next = NULL;
	delete l.tail;
}

void delete_k(LinkedList &l, int k)
{
	int n = count(l);
	if(k < 1 || k > n) return;
	else if(k == 1) delete_front(l);
	else if(k == n) delete_back(l);
	else
	{
		Node *node = l.head;
	for(int i = 0; i < k - 2; i ++)
	{
		node = node -> next;
	}
	Node *afterNode = node -> next;
	node -> next = afterNode -> next;
	delete afterNode;
	}
	
}

void sort(LinkedList &l)
{
	for(Node *i = l.head; i -> next != NULL; i = i -> next)
	{
		Node * Minnode = i;
		for(Node * j = i -> next; j != NULL; j = j -> next)
		{
			if(j -> data < Minnode -> data)
			{
				Minnode = j;
			}
		}
		int tmp = Minnode -> data;
	    Minnode -> data = i -> data;
	    i -> data = tmp;
	}
}

void duyet(LinkedList l)
{
	Node *node = l.head;
	while(node != NULL)
	{
		cout << node -> data << " ";
		node = node -> next;
	}
}

int main()
{
	LinkedList l;
	for(int i = 1; i < 10; i++)
	{
		Node *node = Makenode(i);
		push_front(l, node);
	}
	sort(l);
	duyet(l);

	
	return 0;
}
