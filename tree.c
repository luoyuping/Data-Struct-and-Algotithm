#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char date;
	struct node *Lchild;
	struct node *Rchild;
    _Bool Ltag,Rtag;
} binode,*bitree;



typedef struct stack
{
	binode date;
	struct  stack *next; 
} *stack;



stack init()
{
	stack top;
	top=(stack)malloc(sizeof(struct stack));
	top->next=NULL;
	return top;
}



int push(stack top,binode *p)
{  
	stack temp=(stack)malloc(sizeof(struct stack));
	if(! temp)   return -1;
	temp->date=*p;
	temp->next=top->next;
	top->next=temp;
    return 0;    
}



int empty(stack  top)
{
	if(top->next !=NULL)
		return  0;
	else
		return -1;
}



int pop(stack top,binode *p)
{
	stack t;
    //*p=(binode *)malloc(sizeof(binode));
	if(!empty(top))
	{
		t=top->next;
		top->next=t->next;
		(*p)=t->date;
		free(t);
        return 0;
	}
	printf("empty \n");
	return -1;
}




void creat_bitree(binode ** root)
{
     char ch;

     ch=getchar();
     //scanf("%c",&ch);
     //printf("%c\n", ch);
        if (ch=='^')        
        {
        		*root=NULL;
        }
        else
        {
     	    (*root)=(binode*)malloc(sizeof(binode));
     	    (*root)->date=ch;
            (*root)->Ltag=Rtag=0;
     	    //printf("%c has been created\n",ch);
     	    creat_bitree(&((*root)->Lchild));
     	    creat_bitree(&((*root)->Rchild));
        }
}



void preorder(bitree root,stack s)
{
	printf("enter visit tree\n");
	binode *p=root;
	while(p!=NULL || !empty(s))
	{
		if(p!=NULL)
		{
			printf("%c\n",p->date);
			push(s,p);
			p=p->Lchild;
		}
		else
		{
			p=(binode *)malloc(sizeof(binode));
            pop(s,p);
            p=p->Rchild;
		}
	}
}



void inorder(bitree root,stack s)
{
    printf("enter visit tree\n");
    binode *p=root;
    while(p!=NULL || !empty(s))
    {
    	if(p)
    	{
    		push(s,p);
    		p=p->Lchild;
    	}
    	else
    	{
    		p=(binode *)malloc(sizeof(binode));
    		pop(s,p);
    		printf("%c\n",p->date );
    		p=p->Rchild;

    	}
    }
}






void postorder(bitree root,stack s)
{
	binode *q=NULL;
	printf("enter visit tree\n");
    binode *p=root;
    while(p!=NULL || !empty(s))
    {
        while(!p)
        {
        	push(s,p);
        	p=p->Lchild;
        }  
        if(!empty(s))
        {
            p=(binode *)malloc(sizeof(binode));
            *p=s->next->date;

            if((p->Rchild==NULL)||(p->Rchild==q))
            {
            	p=(binode *)malloc(sizeof(binode));
            	pop(s,p);
            	printf("%c\n",p->date);
            	q=p;
            	p=NULL;

            }
            else          p=p->Rchild;
        }
    }
}



void inthread(bitree root)
{
    bitree p=NULL;
    if(root!=NULL)
    {
        inthread(root->Lchild);
        if(root->Lchild==NULL)
        {
            root->Ltag=1;
            root->Lchild=pre;
        }
        if (pre!=NULL && pre->Rchild==NULL)
        {
            pre->Rchild=root;
            pre->Rtag=1;
        }
        pre=root;
        inthread(root->Rchild);

    }
}




/*

bitree find_leaf(bitree root,stack s)
{
	binode *pre,*p,*temp;
	binode *head=(binode*)malloc(sizeof(binode));

	int count=0;
	p=root;
    while(p!=NULL  || !empty(s))
    {
         if(p!=NULL)
         {
         	//printf("%c ",p->date);
            push(s,p);
            p=p->Lchild;
         }
         else
         {
         	p=(binode *)malloc(sizeof(binode));
         	pop(s,p);
         	temp=p;
         	p=p->Rchild;
         	if(p==NULL && temp->Lchild==NULL)
         		{
         			count ++;
         			if(count==1)      pre=head;
         			pre->Rchild=temp;
         			pre=temp;
         		}
         }
    }
    return head;
}




void print_leaf(binode *head)
{
	printf("\nthe leaf is:\n");
	binode *p;
	p=head->Rchild;
	while(p!=NULL)
	{
		printf("%c ",p->date);
		p=p->Rchild;
	}
	printf("\n\n");

}

*/
  

int main(int argc, char const *argv[])
{
	stack top;
	binode* p;
	binode *head;
	bitree* root=&p;

	top=init();
	printf("input your tree:\n");
	creat_bitree(root);
	preorder(*root,top);
	
	return 0;
}