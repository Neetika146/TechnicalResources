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

Node* middleLL(Node* head){
	if(head==0){
		return NULL;
	}
    Node* f= head;
	Node* s =head;
    while(f->next!=NULL && f->next->next!=NULL){
        f=f->next->next;
        s=s->next;
    }
    return s;
}

Node* reverseLL(Node* head){
	if(head==NULL || head->next==NULL){
		return head;
	}
    Node* p= NULL;
	Node* c =head;
	while(c!=NULL){
        Node* n=c->next;
        c->next=p;
        p=c;
        c=n;
	}
	return p;
}

Node* foldLL(Node* head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	Node* mid=middleLL(head);
	Node* firstLL= head;
	Node* secondLL =mid->next;
	mid->next=NULL;
    secondLL=reverseLL(secondLL);
    Node* ans= new Node(firstLL->data);
    firstLL=firstLL->next;
    Node* ansnode=ans;
    while(secondLL->next!=NULL && firstLL->next!=NULL){
        ans->next=secondLL;
        secondLL=secondLL->next;
        ans=ans->next;
        ans->next=firstLL;
        firstLL=firstLL->next;
        ans=ans->next;
    }
    while(secondLL!=NULL){
        ans->next=secondLL;
        secondLL=secondLL->next;
        ans=ans->next;
    }
    while(firstLL!=NULL){
        ans->next=firstLL;
        firstLL=firstLL->next;
        ans=ans->next;
    }
	return ansnode;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = foldLL(head);
		print(head);
	}

	return 0;
}
