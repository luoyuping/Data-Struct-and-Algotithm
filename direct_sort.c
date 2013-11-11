#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef  struct  node
{
	int  value;
    struct node *next;
}node;


node *creat()
{
	int v;
	node* temp;
    node* head=(node*)malloc(sizeof(node));
    head->next=NULL;
    scanf("%d",&v);
    while(v!=-1)
    { 
         temp=(node*)malloc(sizeof(node));
         temp->value=v;
         temp->next=head->next;
         head->next=temp;


         scanf("%d",&v);

    }

    return head;
}



void add(node *head)
{
    int v;
	node* temp;
    printf("input the value:\n");
    scanf("%d",&v);
    while(v!=-1)
    { 
         temp=(node*)malloc(sizeof(node));
         temp->value=v;
         temp->next=head->next;
         head->next=temp;

         scanf("%d",&v);

    }
   
}


void test(node* head)
{
	node *temp;
	temp=head->next;
	//printf("the linklist is:\n");
	while(temp)
	{
		printf("%d ", temp->value);
		temp=temp->next;
	}
	printf("\n");
}


void insert(node *head,node *q)
{
	node* temp;
	temp=head;
	while(q->value > temp->next->value)
	{
         temp=temp->next;
	}
	q->next=temp->next;
	temp->next=q;
}

void sort(node* head)
{
	node* p,*q,*r,*temp;
	int tag;
    /*
	if(!head->next)   
	{
		printf(" the linklist is empty!\n");
		return;
	}
    */
	p=head->next;
	if(!p->next)    return;

	q=p->next;
	r=q->next;

	while(q->next)
	{
         if(p->value <= q->value)
         {
         	p=p->next;
         	q=q->next;
         	r=r->next;
         }
         else
         {
         	insert(head,q);
         	p->next=r;
         	q=r;
         	r=r->next;
         }
	}
    
    if(p->value > q->value)
    {
         insert(head,q);
         p->next=NULL;
    }

}
int main(int argc, char const *argv[])
{
    node* head;
    head=creat();
    system("clear");
    if(head->next==NULL)
    {
        printf("the link list is empty!\n");
        return 0;
    }
    printf("bofore sort,the linkliast is :\n");
    test(head);
    sort(head);
    printf("after sort,the linklist is :\n");
    test(head);   
	return 0;
}