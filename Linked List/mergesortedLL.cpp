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

Node* mergesortedLL(Node* head1, Node* head2){
    if(head1==NULL){
		return head2;
	}
    if(head2==NULL){
		return head1;
	}
    if(head1==NULL && head2==NULL){
		return NULL;
	}
    int data1;
    if(head1->data <= head2->data){
        data1 = head1->data;
        head1=head1->next;
    }
    else{
        data1 = head2->data;
        head2=head2->next;
    }
    Node* ans= new Node(data1);
    Node*temp =ans;
    while(head1!=NULL && head2!=NULL){
        if(head1->data <= head2->data){
            Node* newnode= new Node(head1->data);
            ans->next=newnode;ans=ans->next;
            head1=head1->next;
        }
        else if(head2->data <= head1->data){
            Node* newnode= new Node(head2->data);
            ans->next=newnode;ans=ans->next;
            head2=head2->next;
        }
    }
    while(head1!=NULL){
        Node* newnode= new Node(head1->data);
        ans->next=newnode;ans=ans->next;
        head1=head1->next;
    }
    while(head2!=NULL){
        Node* newnode= new Node(head2->data);
        ans->next=newnode;ans=ans->next;
        head2=head2->next;
    }
	return temp;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head1 = takeinput();
        Node *head2 = takeinput();
		Node *head = mergesortedLL(head1,head2);
		print(head);
	}

	return 0;
}
