#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  max       15
#define  arc_max         20
#define INFINITY   100

typedef struct name
{
    char name[10];
}Name;

typedef  struct graph
{

	int matrix[max][max];
	int vexnum;
	int arcnum;
	Name name[max];
}graph;



typedef struct Node
{
	int father;
	int son;
	int value;
}Node;



void initgraph(graph *g)
{
	for (int i = 0; i < g->vexnum; ++i)
	{
		for (int j = 0; j < g->vexnum; ++j)
		{
			g->matrix[i][j]=INFINITY;
		}
	}
}



void creat_graph(graph *g)
{
	//initgraph(g);
    printf("input the vexnode number:");
    scanf("%d",&g->vexnum);
    //getchar();

    for (int i = 0; i < g->vexnum; ++i)
    {
    	scanf("%s",g->name[i].name);
    }
    for (int i = 0; i < g->vexnum; ++i)
    {
    	for (int j = 0; j < g->vexnum; ++j)
    	{
    		scanf("%d",&g->matrix[i][j]);
    	}
    }
    printf("\n");



    //test code
    for (int i = 0; i  <g->vexnum; ++i)
    {
    	printf("%s ",g->name[i].name);
    }
    printf("\n");
    for (int i = 0; i < g->vexnum; ++i)
    {
    	for (int j = 0; j < g->vexnum; ++j)
    	{
    		printf("%5d",g->matrix[i][j]);
    	}
    	printf("\n");
    } 
    printf("\n");   

}


void creat_node(Node *node,graph *g)
{
	 int t=1;
	 int count=0;
    FILE *p;
     g->arcnum=0;
     for (int i = 0; i < g->vexnum; ++i)
     {
         for (int j = i; j <g->vexnum ; ++j)
         {
         	if(g->matrix[i][j])
         	{
              node[t].father=i;
              node[t].son=j;
              node[t].value=g->matrix[i][j];
              
              //node[t].tag=0;
              t++;
              g->arcnum ++;

         	}
         }

     }

     //test node
     printf("print node array:(f,s,v,t)\n");
     for (int i = 0; i <= g->arcnum; ++i)
     {
     	printf("%d %d  %d \n", node[i].father,node[i].son,node[i].value);
     	count++;
     }
     printf("totally:%d\n",g->arcnum);

}




void Swap_node(Node* a,Node* b)
{
    Node temp;
    /*
    temp.father=a.father;
    temp.son=a.son;
    temp.value=a.value;

    a.father=b.father;
    a.son=b.son;
    a.value=b.value;

    b.father=temp.father;
    b.son=temp.son;
    b.value=temp.value;
    */

    temp=*a;
    *a=*b;
    *b=temp;

}

void test_sort(Node* node,int length)
{
    for (int i = 0; i <=length ; ++i)
    {
        printf("%d %d %d\n",node[i].father,node[i].son,node[i].value);
    }

    printf("\n");
}


void heap_adjust(Node *node,int length,int s)
{
	int v;
    Node temp ;
	v=node[s].value;
    temp=node[s];
	for (int i = 2*s; i <=length; i*=2) 
	{
		if(i<length && node[i].value >node[i+1].value)
			i++;

		if(temp.value<=node[i].value)
			break;

		node[s].value=node[i].value;
        node[s].father=node[i].father;
        node[s].son=node[i].son;

		s=i;
	}
	node[s]=temp; 
}


void creat_heap(Node *node,int length)
{
	for (int i = length/2; i > 0; --i)
	{
		heap_adjust(node,length,i);
	}
}
void heapsort(Node *node,graph *g)
{
   int length=g->arcnum;
   creat_heap(node,length);
   //printf("first build heap:\n");
   //test_sort(node,g->arcnum);
   printf("\n\n");

   for (int i = length; i > 1; --i)
   {
       //printf("swap before:%d %d\n",node[1].value,node[i].value);
       Swap_node(&node[1],&node[i]);
       //printf("swap after:%d %d\n",node[1].value,node[i].value);
       heap_adjust(node,i-1,1);
       //test_sort(node,g->arcnum);  	  
   }
}




void change(int* parent_tree,int b,int a,int length)                                         
{                                         
    int i,n=parent_tree[b];                                         
    for(i=0;i< length;i++)                                         
    {                                         
        if(parent_tree[i]==n)                                         
        {                                         
            parent_tree[i]=parent_tree[a];                                         
        }                                         
    }                                         
}                                         

void kruskal(graph *g)
{
     
     Node 	*node;
     int length;
     int father;
     int son;
     int i;
     int* parent_tree;
     node=(Node*)malloc(sizeof(Node)*arc_max);

     creat_node(node,g);

     heapsort(node,g);
     test_sort(node,g->arcnum);
     length=g->arcnum;

     parent_tree=(int*)malloc(sizeof(int)*(g->vexnum));

     for (int i = 0; i < g->vexnum; ++i)
     {
          parent_tree[i]=i;
     }  

      printf("the MST tree is:\n");

      for (int i = length; i > 0 ; --i)
      {
        
          father=node[i].father;
          son=node[i].son;
          if(parent_tree[father] != parent_tree[son])
          {
             printf("%d -> %d %d (%s->%s)\n",father,son,node[i].value,g->name[father].name,g->name[son].name);
             change(parent_tree,father,son,g->vexnum); 
          }


      }
}







int main(int argc, char const *argv[])
{
    graph g;
    creat_graph(&g);
    kruskal(&g);
	return 0;
}
