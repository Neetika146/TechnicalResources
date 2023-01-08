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

Node* kreverseLL(Node* head, int k){
	if(head==NULL || head->next==NULL){
		return head;
	}
    Node* p= NULL;
	Node* c =head;
    Node* n;
    int i=0;
	while(c!=NULL && i!=k){
        n=c->next;
        c->next=p;
        p=c;
        c=n;
        i++;
	}
    if(n!=NULL){
        head->next=kreverseLL(n,k);
    }
	return p;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
        int k;
        cin >> k;
		head = kreverseLL(head,k);
		print(head);
	}

	return 0;
}
