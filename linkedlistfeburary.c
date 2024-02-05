#include <stdio.h>
//LINKED LIST OPERATIONS AND MY FIRST PROGRAMME UPLOADED ON GIT HUB

struct node
{
	int data;
	struct node *addr;
}*start,*curr,*newnode,*temp;

void create(int);
void display();
void addAtBegg(int);
void addAtMiddle(int,int);
void addAtEnd(int);
void deleteFromMiddle(int);
int main(int argc, char *argv[]) 
{
	int n,ch,ch2,cnt,pos;
	start=NULL;
	
	do
	{
		printf("\n1-create\n2-display\n3-addAtBeg\n4-addAtMiddle\n5-addAtEnd\n6-deleteFromBegg\n7-deleteFromMiddle");
		printf("\nenter your choice");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				printf("\nenter number to add in linked list");
				scanf("%d",&n);
				create(n);
				display();
				break;
			
			case 2:
				display();
				break;
				
			case 3:
				printf("\nenter any number to add in beggining linked list");
				scanf("%d",&n);
				addAtBegg(n);
				break;
				
			case 4:
				printf("\nenter number and position to add in the middle");
				scanf("%d%d",&n,&pos);
				addAtMiddle(n,pos);
				break;
				
			case 5:
				printf("\nenter any number to add at end");
				scanf("%d",&n);
				addAtEnd(n);
				break;
				
			case 6:
				deleteFirstNode();
				break;
				
			case 7:
				printf("\nenter position to delete");
				scanf("%d",&pos);
				deleteFromMiddle(pos);
				break;
		}
		printf("\ndo you want to continue press 1");
		scanf("%d",&ch2);
	}while(ch2==1);
	printf("\nthank you");
}

	void create(int n)
	{
		newnode=malloc(sizeof(struct node));
		newnode->data=n;
		newnode->addr=NULL;
		
		if(start==NULL)
		{
			start=newnode;
		}
		else
		{
			curr=start;
			while(curr->addr!=NULL)
			{
				curr=curr->addr;
				
			}
			curr->addr=newnode;	
		}
	}
	void display()
	{
		if(start==NULL)
		{
			printf("\nlinked list doesn`t exist");
		}
		else
		{
			curr=start;
			while(curr!=NULL)
			{
				printf("| %d | %u |->",curr->data,curr->addr);
				curr=curr->addr;
			}
		}
	}
	
	void addAtBegg(int n)
	{
		newnode=malloc(sizeof(struct node));
		newnode->data=n;
		newnode->addr=start;
		start=newnode;
	}
	
	void addAtMiddle(int n,int pos)
	{
		
		curr=start;
		int cnt=1;
		while(cnt<pos-1)
		{
			curr=curr->addr;
			cnt++;
		}
		newnode=malloc(sizeof(struct node));
		newnode->data=n;
		newnode->addr=curr->addr;
		curr->addr=newnode;
	}
	
	void addAtEnd(int n)
	{
		newnode=malloc(sizeof(struct node));
		newnode->data=n;
	
		curr=start;
		while(curr->addr!=NULL)
		{
			curr=curr->addr;
		}
		curr->addr=newnode;
		newnode->addr=NULL;
		printf("\nnode inserted");
	}
	
	void deleteFirstNode()
	{
		curr=start;
		start=curr->addr;
		curr->addr=NULL;
		free(curr);
		printf("\node deleted");
	}
	
	void deleteFromMiddle(int pos)
	{
		curr=start;
		temp=start;
		int cnt=1;
		while(cnt<pos-1)
		{
			curr=curr->addr;
			temp=temp->addr;
			cnt++;
		}
		temp=temp->addr;
		curr->addr=temp->addr;
		temp->addr=NULL;
		free(temp);
		
	}

