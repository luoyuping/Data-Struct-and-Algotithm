#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  n   4
#define  m   2*n


typedef struct 
{
   int weight;
   int parent,Lchild,Rchild;
   char ch;
   //_Bool   tag;

}node;



typedef struct
{
   char code[n];
   char ch;

}huffcode;




void find_min(node *p[m],int count,int *min,int *smin)
{
	*min=*smin=0;
	for (int i = 1; i <=count; ++i)
	{
		if((p[i]->weight < p[*min]->weight)&&(p[i]->parent==0))  //update the maxium and the 
		{	                                                     // second largest value
			*smin = *min;
            *min = i;
        }
        else
        {
           if((p[i]->weight < p[*smin]->weight)&&(p[i]->parent==0)) //update the second largest
        	*smin = i;
        }                                              //value
	}
}




void creat_huff(node *p[m],int weight[n])
{
    int min,smin;
	for (int i = 1; i <= n; ++i)
		p[i]->weight=weight[i];

	for (int j = 0; j < m; ++j)
		p[j]->Lchild=p[j]->Rchild=p[j]->parent=0;

	
	for (int i = n+1; i <m ; ++i)
		p[i]->weight=0;
    
    for (int i = n+1; i <m; ++i)
    {
    	find_min(p,i-1,&min,&smin);
        p[i]->weight=p[min]->weight+p[smin]->weight;
        p[i]->Lchild=min;
        p[i]->Rchild=smin;

        p[min]->parent=p[smin]->parent=i;
    }
}




void printtree(node *p[m])
{
	printf("the information of the tree is:\n");
	for (int i = 0; i < m; ++i)
	{
		printf("%d %d %d %d \n",p[i]->weight,p[i]->parent,p[i]->Lchild,p[i]->Rchild);
	}
}



void get_code(node *p[m],huffcode *q[n])
{
    char *temp=(char*)malloc(sizeof(char)*n);
    int subscript;
    int pre,parent;
    temp[n-1]='\0';
    for (int i = 1; i <=n ; ++i)
    {
        subscript=n-2;
        pre=i;
        parent=p[i]->parent;
        while(p)
        {
            if(p[parent]->Lchild==pre)
                temp[subscript--]='0';
            else
                temp[subscript--]='1';
            pre=parent;
            parent=p[pre]->parent;
        }
        strcpy(q[i]->code,temp);
    }

    free(temp);
}



void translate(node *p[m],char *source,int x,char *tag)
{ 
    
        
}



int main(int argc, char const *argv[])
{
    node *p[m];
    int max=0;
    int weight[n];
    huffcode *q[n];

    for (int i = 0; i < m; ++i)
    	p[i]=(node*)malloc(sizeof(node));

    for (int i = 0; i < n; ++i)
        q[i]=(huffcode*)malloc(sizeof(huffcode));        

    for (int i = 1; i <=n; ++i)
    	scanf("%d",&weight[i]);

    for (int i = 1; i <=n; ++i)
    	max+=weight[i];

    p[0]->weight=max;

    creat_huff(p,weight);
    printtree(p);
}            



