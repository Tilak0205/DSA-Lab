#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;

void InsertAtBeg(void)
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data: ");
	scanf("%d",&newnode->data);
	newnode->left=newnode->right=NULL;
	if(root==NULL){
		root=newnode;
		newnode->left=newnode->right=root;
	}
	else{
		temp=root;
		while(temp->right!=root){
			temp=temp->right;
		}
		temp->right=newnode;
		newnode->right=root;
		root->left=newnode;
		root=newnode;
	}
}

void InsertAtPos(void)
{
	struct node *newnode,*p,*q;
	int pos;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the position to insert: ");
	scanf("%d",&pos);
	newnode->left=newnode->right=NULL;
	if(pos==1){
		InsertAtBeg();
	}
	else{
		printf("\nEnter the data: ");
		scanf("%d",&newnode->data);
		int i;
		p=root;
		q=p->right;
		for(i=1;i<pos-1;i++){
			p=p->right;
			q=q->right;
		}
		newnode->right=q;
		q->left=newnode;
		newnode->left=p;
		p->right=newnode;
	}
}

void InsertAtEnd(void)
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data: ");
	scanf("%d",&newnode->data);
	if(root==NULL){
		root=newnode;
		newnode->right=newnode->left=root;
	}
	else{
		temp=root;
		while(temp->right!=root){
			temp=temp->right;
		}
		temp->right=newnode;
		newnode->left=temp;
		newnode->right=root;
	}
}

void DeleteFirstNode(void)
{
	struct node *temp,*p;
	if(root->left==root && root->right==root){
		free(root);
		root=NULL;
	}
	else{
		p=temp=root;
		while(temp->right!=root){
			temp=temp->right;
		}
		temp->right=root->right;
		root=root->right;
		free(p);
	}
}

void DeleteLastNode(void)
{
	struct node *p,*q;
	p=root;
	q=p->right;
	if(root==NULL){
		printf("\nList is empty");
	}
	else{
		if(root->right==root && root->left==root){
			free(root);
			root=NULL;
		}
		else{
			while(q->right!=root){
				p=p->right;
				q=q->right;
			}
			p->right=root;
			free(q);
		}
	}
}

int Length(void)
{
	int count=0;
	struct node *temp;
	temp=root;
	if(root->right==root){
		count++;return count;
	}
	else{
		while(temp->right!=root){
			count++;
			temp=temp->right;
		}
		count++;
		return count;
	}
}

void DeletePosNode(void)
{
	struct node *p,*q;
	int pos;
	printf("\nEnter the position to delete: ");
	scanf("%d",&pos);
	if(pos==1){
		DeleteFirstNode();
	}
	else if(pos==Length()){
		DeleteLastNode();
	}
	else{
		p=root;
		q=p->right;
		int i;
		for(i=1;i<pos-1;i++){
			p=p->right;
			q=q->right;
		}
		p->right=q->right;
		q->right=q->left=NULL;
		free(q);
	}
}

void display(void)
{
	struct node *temp;
	if(root==NULL){
		printf("\nList is empty");
	}
	else{
		temp=root;
		while(temp->right!=root){
			printf("%d ",temp->data);
			temp=temp->right;
		}
		printf("%d",temp->data);
	}
}


int main()
{
	int ch,len;
	printf("Doubly Circular linked list operations");
	while(1){
		printf("\n\n1.Insert at beginning");
		printf("\n2.Insert at given pos");
		printf("\n3.Insert at end");
		printf("\n4.Delete first node");
		printf("\n5.Delete at given pos");
		printf("\n6.Delete last node");
		printf("\n7.Length of the LList");
		printf("\n8.Display");
		printf("\n9.Exit");
		printf("\n\nChoose any option: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: InsertAtBeg();break;
			case 2: InsertAtPos();break;
			case 3: InsertAtEnd();break;
			case 4: DeleteFirstNode();break;
			case 5: DeletePosNode();break;
			case 6: DeleteLastNode();break;
			case 7: len=Length(); printf("\nThe length is %d",len);break;
			case 8: display();break;
			case 9: exit(1); break;
			default: printf("\nChoose a valid option");
		}
	}
}
