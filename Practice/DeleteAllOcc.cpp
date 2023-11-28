#include<iostream>
using namespace std;
class node
{
	public:
		node* next;
		int val;
    node(int data)
    {
    	next=NULL;
    	val=data;
	}
};
void push(node* &head,int v)
{
	node* nn=new node(v);
	if(head==NULL)
	{
		head=nn;
		return;
	}
	else
	{
		node* temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=nn;
	}
	
}
void deleteAt(node* &head)
{
	node* todelete=head;
	head=head->next;
	delete (todelete);
}

void count(node* head,int key)
{
	int c=0;
	if(head==NULL)
	{
		cout<<"list is empty"<<endl;
		return ;
	}
		while(head->val==key)
		{
			c++;
			deleteAt (head);
	}
	node* temp=head;
	while(temp!=NULL)
	{
	if(temp->next->val==key)
		{
			c++;
			node* todelete=temp->next;
			temp->next=temp->next->next;
			delete (todelete);
		
		}
			temp=temp->next;
		
	}
	cout<<c<<endl;
	
	}
	void display(node* head)
	{
	
		if(head==NULL)
		{
			cout<<"empty"<<endl;
			return;
		}
		else
		{
			node* temp=head;
			while(temp!=NULL)
			{
				cout<<temp->val<<"->";
				temp=temp->next;
			}
			
		}}
	
	int main()
	{
		node* head=NULL;
		push(head,1);
		push(head,2);
		push(head,1);
		push(head,2);
		push(head,1);
		push(head,3);
		push(head,1);
			count(head,1);
	display(head);
	
	}