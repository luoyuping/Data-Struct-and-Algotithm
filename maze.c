#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  m   11
#define  n   10
int map[m][n]={ 
               {1,    1,1,1,1,1,1,1,1,       1},

                //     1 2 3 4 5 6 7 8
               {1,     0,0,1,0,0,0,1,0,       1},//1
               {1,     0,0,1,0,0,0,1,0,       1},//2
               {1,     0,0,0,0,1,1,0,1,       1},//3
               {1,     0,1,1,1,0,0,1,0,       1},//4
               {1,     0,0,0,1,0,0,0,0,       1},//5
               {1,     0,1,0,0,0,1,0,1,       1},//6
               {1,     0,1,1,1,1,0,0,1,       1},//7
               {1,     1,1,0,0,0,1,0,1,       1},//8
               {1,     1,1,0,0,0,0,0,0,       1},//9
                //     1 2 3 4 5 6 7 8

               {1,    1,1,1,1,1,1,1,1,       1} 
               
              };

_Bool visit[m][n]={
               {1,1,1,1,1,1,1,1,1,1},
               {1,0,0,0,0,0,0,0,0,1},
               {1,0,0,0,0,0,0,0,0,1},
               {1,0,0,0,0,0,0,0,0,1},
               {1,0,0,0,0,0,0,0,0,1},
               {1,0,0,0,0,0,0,0,0,1},
               {1,0,0,0,0,0,0,0,0,1},
               {1,0,0,0,0,0,0,0,0,1},
               {1,0,0,0,0,0,0,0,0,1},
               {1,0,0,0,0,0,0,0,0,1},
               {1,1,1,1,1,1,1,1,1,1}
                 };


char way[m][n]={
               {'1','1','1','1','1','1','1','1','1','1'},
               {'1','0','0','0','0','0','0','0','0','1'},
               {'1','0','0','0','0','0','0','0','0','1'},
               {'1','0','0','0','0','0','0','0','0','1'},
               {'1','0','0','0','0','0','0','0','0','1'},
               {'1','0','0','0','0','0','0','0','0','1'},
               {'1','0','0','0','0','0','0','0','0','1'},
               {'1','0','0','0','0','0','0','0','0','1'},
               {'1','0','0','0','0','0','0','0','0','1'},
               {'1','0','0','0','0','0','0','0','0','1'},
               {'1','1','1','1','1','1','1','1','1','1'}
                 };


typedef  struct stack
{
	int x,y;
	int dir;
	struct stack *next;
}  stack;



stack * init()
{
	stack *top;
	top=(stack*)malloc(sizeof(stack));
	top->next=NULL;
	return top;
}




void push(stack *top,stack *temp)
{
    stack *p=(stack *)malloc(sizeof(stack));
    if (!p)          return;
    p->x=temp->x;
    p->y=temp->y;
    p->dir=temp->dir;
    
    p->next=top->next;
    top->next=p;

}



void  pop(stack *top,stack * temp)
{
	stack *p;
	if(top->next!=NULL)
	{
      p=top->next;

	    temp->x=p->x;
	    temp->y=p->y;
	    temp->dir=p->dir;

	    top->next=p->next;
	    free(p);
	}
}





void print_stack(stack *top)
{
    stack *s;
    s=top->next;
    printf("from  end to start\n");
    while(s!=NULL)
    {
    	printf("%d %d %d\n", s->x,s->y,s->dir);
        s=s->next;
    }
}


/*
void test_stack()
{
    stack* top;
    stack *temp=(stack*)malloc(sizeof(stack));
    top=init();
    printf("input the x,y,dir\n");
    while(1)
    {
        scanf("%d%d%d",&temp->x,&temp->y,&temp->dir);
        if(temp->x==0 &&temp->y==0 &&temp->dir==0)
            break;
        push(top,temp);
    }
    print_stack(top);
    printf("pop........\n");
    while(top->next)
    {
        pop(top,temp);
        printf("%d %d %d\n",temp->x,temp->y,temp->dir);
    }
    scanf("%d%d%d",&temp->x,&temp->y,&temp->dir);
    push(top,temp);
    pop(top,temp);
    printf("%d %d %d\n",temp->x,temp->y,temp->dir);

}

*/
int move(stack *top,stack *temp,int sx,int sy)
{
  int dir;

	 switch(temp->dir)

	 {
	 	case 0:
	 	       ++ temp->y;
	 	       break;
	 	case 1:
	 	       ++ temp->x;
	 	       break;
	 	case 2:
	 	       -- temp->y;
	 	       break;
	 	case 3:
	 	       -- temp->x;
               break;
	 	default:

	 	       pop(top,temp);
           printf("the (%d,%d) dir=%d ,is out of the stack\n",temp->x,temp->y,temp->dir);

           if((temp->x==sx) && (temp->y==sy))   return -1;

	 	       temp->x=top->next->x;
               temp->y=top->next->y;
               temp->dir ++;
	 	       move(top,temp,sx,sy);
	 }
   return 0;
}


void reset(stack *temp)
{
    switch(temp->dir)
    {
        case 0:
               -- temp->y;
               break;
        case 1:
               -- temp->x;
               break;
        case 2:
               ++ temp->y;
               break;
        case 3:
               ++ temp->x;
               break;
    }
}

void show_way(stack *top)
{
    printf("\n\n\n\n\n");
    stack *temp=(stack *)malloc(sizeof(stack));
      
    while(top->next)
    {
        pop(top,temp);
        printf("(%d,%d)<<==",temp->x,temp->y);
        way[temp->x][temp->y]=42;
         
    }
    printf("\n\n\nas it showing in the following map:\n");
    for (int i = 1; i < m-1; ++i)
    {
        for (int j = 1; j <n-1 ; ++j)
        {
            printf("%c ", way[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
}



void dfs(stack *top,int sx,int sy,int ex,int ey)
{  
	   top=init();
     stack *temp=(stack *)malloc(sizeof(stack));
     
     temp->x=sx;temp->y=sy;temp->dir=0;
     if(map[sx][sy]==1)
     {
     	printf("the entrance is blocked\n");
     	return ;
      //exit(0);
     }
     push(top,temp);
     printf("the  (%d,%d) was put in the stack\n",temp->x,temp->y);
     visit[sx][sy]=1;
     while(top->next)
     {
         if(move(top,temp,sx,sy))            break;
         //visit[temp->x][temp->y]==1;
         if(map[temp->x][temp->y]==1)
         {
            printf("the (%d,%d) is blocked\n",temp->x,temp->y );
            reset(temp);
            printf("back to (%d,%d)\n",temp->x,temp->y );
         	  temp->dir ++;
            
         	continue;
         }
         if(visit[temp->x][temp->y]==1)
         {
            printf("the (%d,%d) has been visited\n",temp->x,temp->y);
            reset(temp);
            printf("back to (%d,%d)\n",temp->x,temp->y );
         	  temp->dir ++;
            
          	continue;
         }
         visit[temp->x][temp->y]=1;
         push(top,temp);
         
         printf("the  (%d,%d)was put in the stack\n",temp->x,temp->y);
         temp->dir=0;
         if ((temp->x==ex)&&(temp->y==ey))
         {
            show_way(top);
         	  return ;
         }
     }
     printf("there is no way you can get out of the maze!\n");
}


void printmap()
{
    for (int i = 1; i < m-1; ++i)
    {
        for (int j = 1; j < n-1; ++j)
        {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main(int argc, char const *argv[])
{
	stack *top;
    int sx,sy,ex,ey;
    //test_stack();
    
    
    printmap();
    printf("\n\nplease input your entrance and exit:\n");
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    if(sx<0 ||sy<0 ||ex<0 ||ey<0 ||sx>m-2 ||sy>n-2 ||ex>m-2 ||ey>n-2 )
        {
            printf("wrong \n");
            return  0;
        }
    getchar();
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    dfs(top,sx,sy,ex,ey);
    
    
	return 0;
}