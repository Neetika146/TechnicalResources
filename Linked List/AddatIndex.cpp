#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node* addatIndex(Node* head, int pos, int val){
    Node* temp= head;
    int i=1;
    while(i!=pos){
        i++;
        temp=temp->next;
    }
    Node* newnode = new Node(val);
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int pos,val;
		cin >> pos >> val;
		head = addatIndex(head, pos, val);
		print(head);
	}

	return 0;
}
