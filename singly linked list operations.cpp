#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
};
struct node *root=NULL;

void InsertAtBeg(void)
{
	struct node *newnode,*temp;
	newnode=(struct node* )malloc(sizeof(struct node));
	printf("\nEnter the data: ");
	scanf("%d",&newnode->data);
	newnode->link=NULL;
	if(root==NULL){
		root=newnode;
	}
	else{
		newnode->link=root;
		root=newnode;
	}
}

void InsertAtPos(void)
{
	struct node *newnode,*p,*q;
	int pos;
	newnode=(struct node* )malloc(sizeof(struct node));
	printf("\nenter the position to insert: ");
	scanf("%d",&pos);
	printf("\nEnter the data: ");
	scanf("%d",&newnode->data);
	newnode->link=NULL;
	if(root==NULL){
		root=newnode;
	}
	else{
		int i;
		p=root;
		q=p->link;
		for(i=1;i<pos-1;i++){
			p=p->link;
			q=q->link;
		}
		newnode->link=q;
		p->link=newnode;
		
	}
}

void InsertAtEnd(void)
{
	struct node *newnode,*temp;
	newnode=(struct node* )malloc(sizeof(struct node));
	printf("\nEnter the data: ");
	scanf("%d",&newnode->data);
	newnode->link=NULL;
	if(root==NULL){
		root=newnode;
	}
	else{
		temp=root;
		while(temp->link!=NULL){
			temp=temp->link;
		}
		temp->link=newnode;
	}
}

void DeleteFirstNode(void)
{
	struct node *temp;
	temp=root;
	root=root->link;
	free(temp);
}


void DeleteLastNode(void)
{
	struct node *p,*q;
	p=root;
	q=p->link;
	if(root==NULL){
		printf("\nList is empty");
	}
	else{
		if(root->link==NULL){
			root=NULL;
		}
		else{
			while(q->link!=NULL){
				p=p->link;
				q=q->link;
			}
			p->link=NULL;
			free(q);
		}
	}
}

int Length(void)
{
	int count=0;
	struct node *temp;
	temp=root;
	while(temp!=NULL){
		count++;
		temp=temp->link;
	}
	return count;
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
		q=p->link;
		int i;
		for(i=1;i<pos-1;i++){
			p=p->link;
			q=q->link;
		}
		p->link=q->link;
		q->link=NULL;
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
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->link;
		}
	}
}


int main()
{
	int ch,len;
	printf("Singly linked list operations");
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
