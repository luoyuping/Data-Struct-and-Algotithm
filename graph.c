#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  max 20

typedef struct node 
{
	int v;
    struct node *next;
} node;

typedef struct Head
{
    node *head;
    char ch;

}Head;

typedef struct 
{
	Head  head_array[max];
	int vexnum;
	int arcnum;
}graph;



void creat_graph(graph *g)
{    
	 int m;
	 node *temp;


     printf("please input your graph\n");
     printf("vexnum?:");
     scanf("%d",&g->vexnum);
     printf("\n");
     printf("arcnum? :");
     scanf("%d",&g->arcnum);
     printf("\n");
     for (int i = 0; i < g->vexnum; ++i)
     {
     	 g->head_array[i].head=(node*)malloc(sizeof(node));
     	 g->head_array[i].head->next=NULL;

      	 printf("the  %dth vex:\n",i+1);
         printf("name?:");
         getchar();
         scanf("%c",&(g->head_array[i].ch));
         //getchar();
         printf("how many points connect to point %c ?:", g->head_array[i].ch);
         scanf("%d",&m);
         for (int j = 0; j < m; ++j)
         {
         	temp=(node*) malloc(sizeof(node));
         	scanf("%d",&(temp->v));
         	temp->next=g->head_array[i].head->next;
         	g->head_array[i].head->next=temp;
         }
     }
     printf("creat over\n");
}



void test_graph(graph *g)
{
	 node *p;
	 printf("the graph is as follow:\n");
     for (int i = 0; i < g->vexnum; ++i)
      {
      	 printf("the %dth:\n",i);
      	 p=g->head_array[i].head->next;
      	 printf("%c\n",g->head_array[i].ch);
      	 while(p)
      	 {
            printf("%d  ",p->v);;
            p=p->next;
      	 }
      	 printf("\n");
      } 
}



void visit(int vex)
{
	printf("visit %c ",g->head_array[vex].ch);
}


void dfs_recursion(graph *g,int start,int *a)
{
    node *p;
    visit(start);
    a[start]=1;
    p=g->head_array[start].head->next;

    while(p)
    {
    	if(!a[p->v])   dfs(g,p->v,a);
    	p=p->next;
    }

}




void traverse_dfs(graph* g)
{
    int a[g->vexnum];
    for (int i = 0; i < g->vexnum; ++i)
    	a[i]=0;
    for (int i = 0; i < g->vexnum; ++i)
    {
    	if(!visit[i])   dfs(g,i,a);
    }

} 


void  bfs(graph *g,int start,int *a)
{

}

int main(int argc, char const *argv[])
{
	graph *g;
	g=(graph*)malloc(sizeof(graph));
	creat_graph(g);
	test_graph(g);

	return 0;
}