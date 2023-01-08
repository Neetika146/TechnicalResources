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

bool compareLL(Node* a, Node* b){
    if(a==NULL || b==NULL){
        return false;
    }
    return a->data==b->data;
}

bool palindromeLL(Node* head){
	if(head==NULL || head->next==NULL){
		return true;
	}
	Node* mid=middleLL(head);
    mid->next= reverseLL(mid->next);
    Node* temp =mid->next;

    while( temp!=NULL){
        if(head->data!=temp->data){
            return false;
        }
        head=head->next;
        temp=temp->next;
    }
    return true;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		cout<< palindromeLL(head);
	}

	return 0;
}
