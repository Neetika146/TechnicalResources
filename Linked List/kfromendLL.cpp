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

void kfromend(Node* head, int k){
	if(head==NULL){
		return;
	}
    Node* f= head;
	Node* s =head;
    int i=0;
	while(i!=k){
        f=f->next;
        i++;
	}
    while(f!=NULL){
        f=f->next;
        s=s->next;
    }
    cout<<s->data;
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
		kfromend(head,k);
	}

	return 0;
}
