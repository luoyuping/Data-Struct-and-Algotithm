#include <stdio.h>
#include <stdlib.h>
#define m 4
#define n 3

typedef struct
{
   int col[n];
   int count;

}Min;

typedef struct
{
    int row[m];
    int count;
}Max;


struct T
{
    int col;
    int row;
    struct T *next;
};

typedef struct T Trimatrix;

Trimatrix* init()
{
  Trimatrix * head=(Trimatrix*)malloc(sizeof(Trimatrix));
  head->next=NULL;
  return head;
}


void insert(Trimatrix *head,int col,int row)
{
   Trimatrix *s=(Trimatrix*)malloc(sizeof(Trimatrix));

   s->col=col;
   s->row=row;

   s->next=head->next;
   head->next=s;

}
  
void  input(int (*c)[n] )
{

   printf("input the matrix:\n");
   printf("Attion:it should be:%d*%d\n",m,n);
   for(int i=0;i<m;i++)
   {
      for(int j=0;j<n;j++)
      {
         scanf("%d",&c[i][j]);
      }
   }
   getchar();
}


void display_mix(int(*c)[n])
{
  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
         printf("%d ",c[i][j]);
    }
    printf("\n");
  }
}


void find_min(int(*c)[n],Min min[])
{   
    int min_col;
    //int count;
    for(int i=0;i<m;i++)
    {
       min_col=c[i][0];
       min[i].count=0;
       for(int j=1;j<n;j++)
           if(c[i][j] < min_col)    min_col=c[i][j];

       for (int j = 0; j < n; ++j)
           if(c[i][j]==min_col)       min[i].col[min[i].count ++]=j;
    }
}



void find_max(int (*c)[n],Max x[])
{
    int max_row;
    
    for (int i = 0; i < n; ++i)
    {
      max_row=c[0][i];
      x[i].count=0;
      for (int j = 1;  j< m; ++j)
          if (c[j][i]>max_row)       max_row=c[j][i];
      for (int j = 0; j < m; ++j)
          if (c[j][i]==max_row)      x[i].row[x[i].count ++]=j;
    }
}        


void display(Max max[],Min min[])
{
    printf("the max:\n");  
    for (int i = 0; i < n; ++i)
      {
        printf("%d  ", max[i].count);
      }

    printf("\nthe min\n");
    for (int i = 0; i < m; ++i)
      {
        printf("%d  ",min[i].count);
      }    
       
    printf("\n"); 
      
    
}

void  match(Min  min[],Max max[],Trimatrix * head)
{    
    int col;
    

    for (int i = 0; i < m; ++i)
    {
      for (int  j= 0; j < min[i].count; ++j)
      {
         col=min[i].col[j];
         for (int z = 0; z < max[col].count; ++z)
         {
            if(max[col].row[z]==i)
               insert(head,min[i].col[j],i);
         }
      }
    }
}



void print(Trimatrix *head,int (*matrix)[n])
{
     Trimatrix *p;
     p=head->next;
     if(head->next==NULL)
     {
        printf("can not find such one\n");
     }
     else
     {
        printf("an_dian is :\n");
        while(p!=NULL)
        {
             printf("(%d,%d)-----%d\n",p->row,p->col,matrix[p->row][p->col]);
             p=p->next;
        }
     }
}



int main()
{
    int matrix[m][n];
    Trimatrix *head;
    Min  min[m];
    Max  max[n];
    head=init();
    input(matrix);
    display_mix(matrix);
    find_max(matrix,max);
    find_min(matrix,min);
    display(max,min);
    match(min,max,head);
    print(head,matrix);

    return 0;

}