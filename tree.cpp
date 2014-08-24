#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<cstdio>
using namespace std;
class node{
	
	public:
	int data;
	node *left;
	node *right;
	
	node()
	{
		left = NULL;
		right = NULL;
		data = 0;
	}
	node(int n)
	{
		left = NULL;
		right = NULL;
		data = n;
	}
};
class tree{
	public:
	node *root;
	tree(int n)
	{
		root = new node(n);
	}
	void insertNode(int n)
	{
		cout<<"Inserting Data";
		node* temp = root;
		node* temp2 = new node(n);
		while(temp!=NULL)
		{
			if(n>temp->data &&temp->right!=NULL)
			{
				cout<<"right";
				temp = temp->right;
			}
			if(n>temp->data &&temp->right==NULL)
			{
				temp->right = temp2;
				cout<<"Added";
				return;
			}
			if(n<temp->data &&temp->left!=NULL)
			{
				cout<<"Left";
				temp = temp->left;
			}
			if(n<temp->data &&temp->left==NULL)
			{
				temp->left = temp2;
				cout<<"Added";
				return;
			}
		}
	}
	void displayTree()
	{
		inorderTraversal(root);
		
	}
	void inorderTraversal(node *temp)
	{
		if(temp == NULL)
		return;
		
		if(temp->left!=NULL)
		inorderTraversal(temp->left);
		
		cout<<temp->data<<endl;
		
		if(temp->right!=NULL)
		inorderTraversal(temp->right);
		
		return;
	}
};
int main()
{
	int rootData = 100;
	tree *treeA = new tree(rootData);
	int ch =1;
	treeA->displayTree();
	/*while(ch!=0)
	{
		switch(ch){
			case 1 : 
					int data;
					cin>>data;
					treeA->insertNode(data);
					cout<<"Enter Choice Again : ";
					cin>>ch;
					break;
			case 2 : treeA->displayTree();
					  cout<<"Enter Choice Again : ";
					  cin>>ch;
					  break;
			
		}
		
	}*/
	cout<<"Enter Data";
	cin>>ch;
	while(ch>0)
	{
		treeA->insertNode(ch);
		cout<<"Enter Data";
		cin>>ch;
	}
	treeA->displayTree();
	return 0;
}
