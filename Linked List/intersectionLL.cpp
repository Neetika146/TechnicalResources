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

bool mergedLL(Node* a, Node* b){
    if(a==NULL || b==NULL){
        return false;
    }
    while(a!=NULL && b!=NULL){
        if(a!=b){
            return false;
        }
        a=a->next;
        b=b->next;
    }
    return true;
} 
Node *intersectionNode(Node *headA, Node *headB) {
    if(headA==NULL || headB==NULL){
        return NULL;
    }
    int i=0,j=0;
    Node* tempA=headA;
    Node* tempB=headB;
    while(tempA){
        i++;
        tempA=tempA->next;
    }
    while(tempB){
        j++;
        tempB=tempB->next;
    }
    if(i>j){
        int k=i-j;
        while(k--){
            headA=headA->next;
        }
    }
    else{
        int k=j-i;
        while(k--){
            headB=headB->next;
        }
    }
    while(headA!=NULL && headB!=NULL){
        if(mergedLL(headA,headB)){
            return headA;
        }
        headA=headA->next;
        headB=headB->next;
    }
    return NULL;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *headA = takeinput();
        Node *headB = takeinput();
		Node* head = intersectionNode(headA,headB);
		print(head);
	}

	return 0;
}
