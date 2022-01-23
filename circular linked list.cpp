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
	if(root==NULL){
		root=newnode;
		newnode->link=root;
	}
	else{
		temp=root;
		while(temp->link!=root){
			temp=temp->link;
		}
		temp->link=newnode;
		newnode->link=root;
		root=newnode;
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
		newnode->link=root;
	}
	else{
		temp=root;
		while(temp->link!=root){
			temp=temp->link;
		}
		temp->link=newnode;
		newnode->link=root;
	}
}

int Length(void)
{
	int count=0;
	struct node *temp;
	temp=root;
	if(temp==NULL){
		return count;
	}
	else{
		while(temp->link!=root){
			count++;
			temp=temp->link;
		}
		count++;
		return count;
	}
}

void InsertAtPos(void)
{
	struct node *newnode,*p,*q;
	int pos;
	newnode=(struct node* )malloc(sizeof(struct node));
	printf("\nenter the position to insert: ");
	scanf("%d",&pos);
	if(pos==1){
		InsertAtBeg();
	}
	else{
		printf("\nEnter the data: ");
		scanf("%d",&newnode->data);
		newnode->link=NULL;
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

void DeleteFirstNode(void)
{
	struct node *temp,*p;
	p=temp=root;
	if(root==NULL){
		printf("\nThe list is empty");
	}
	else{
		if(root->link==root){ //if one node is there
			root=NULL;
			free(root);
		}
		else{
			while(temp->link!=root){
				temp=temp->link;
			}
			temp->link=root->link;
			root=root->link;
			free(p);
		}
	}
	
}


void DeleteLastNode(void)
{
	struct node *p,*q;
	if(root==NULL){
		printf("\nList is empty");
	}
	else{
		if(root->link==root){ //if one node is there
			root=NULL;
			free(root);
		}
		else{
			p=root;
			q=p->link;
			while(q->link!=root){
				q=q->link;
				p=p->link;
			}
			p->link=root;q->link=NULL;
			free(q);
		}
		
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
		while(temp->link!=root){
			printf("%d ",temp->data);
			temp=temp->link;
		}
		printf("%d",temp->data);
	}
}


int main()
{
	int ch,len;
	printf("Circular linked list operations");
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
