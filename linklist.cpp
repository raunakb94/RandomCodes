#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct node{
	int data;
	node *next;
};
void pushAtStart(struct node **head,int data)
{
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->data = data;
	temp->next = (*head);
	*head = temp;
}
void printList(struct node **head)
{
	struct node *temp = NULL;
	temp = *head;
	cout<<"Beginning Output";
	while(temp!=NULL)
	{
		cout<<"Data"<<temp->data<<endl;
		temp=temp->next;
	}
}
int listSize(struct node **head)
{
	struct node *temp = *head;
	int count = 0;
	while(temp!=NULL)
	{
		++count;
		temp=temp->next;
	}
	return count;
}
void addAfterNode(struct node *nodeA,struct node *nodeB)
{
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->data = nodeB->data;
	//struct node *temp2 = nodeA->next;
	temp->next = nodeA->next;
	nodeA->next = temp;
}
void deleteNode(struct node **head,struct node *delNode)
{
	struct node * temp = (*head)->next;
	struct node * prev = *head;
	if(*head == delNode)//Node to be deleted is the first NOde
	{
		struct node * del = prev;
		*head = (*head)->next;
		del ->next = NULL;
		return;
	}
	while(temp!=delNode)
	{	prev = prev ->next;
		temp = temp ->next;
	}
	prev->next = temp->next;
	temp->next = NULL;
	return;
}
void addAlternate(struct node **head1,struct node **head2)
{
	int sizeA = listSize(head1);
	int sizeB = listSize(head2);
	struct node *tempA = *head1;
	struct node *tempB = *head2;
	if(sizeA<sizeB)
	sizeB=sizeA;
	for(int i=0;i<sizeB;i++)
	{
		addAfterNode(tempA,tempB);
		tempA = tempA->next;
		struct node * prev = tempB;
		tempB = tempB->next;
		deleteNode(head2,prev);
	}
}
int main()
{
	struct node* listA = NULL;
	struct node* listB=NULL;
	int aSize,bSize;
	cin>>aSize;
	int temp = aSize;
	while(temp>0)
	{
		int tempData;
		cin>>tempData;
		pushAtStart(&listA,tempData);
		temp--;
	}
	cout<<"Size of list B";
	cin>>bSize;
	temp = bSize;
	while(temp>0)
	{
		int tempData;
		cin>>tempData;
		pushAtStart(&listB,tempData);
		temp--;
	}
	printList(&listA);
	printList(&listB);
	return 0;
	
}
