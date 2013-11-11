#include <stdio.h>
#include <stdlib.h>

#define  MAX     100

typedef struct  
{
	int col,row;
	int value;

} Triple;



typedef struct 
{
	Triple date[MAX];
	int Row,Col;      
	int Num;
}squeeze_matrix;



squeeze_matrix* init();
void input(int ,int , int(*)[]);
void translate(squeeze_matrix *,int ,int ,int (*)[]);
squeeze_matrix* transpose_way1(squeeze_matrix *);
squeeze_matrix* transpose_way2(squeeze_matrix *);
squeeze_matrix* transpose_way3(squeeze_matrix *);

void print_matrix(int,int n,int (*)[n]);
void print_squ_matrix(squeeze_matrix *);


//_______________________________________________________________//             mian function
int main(int argc, char const *argv[])
{
	
	return 0;
}

//________________________________________________________________



squeeze_matrix * init()
{
	squeeze_matrix * s=(squeeze_matrix *)malloc(sizeof(squeeze_matrix));
	if(!s)    return NULL;
	s->Row=s->Col=s->Num=0;
	return s;
}



void input(int m,int n,int(*mx)[n])
{
     for(int i=0;i<m;i++)
     {
     	for (int j = 0; j < n; ++j)
     	{
     		scanf("%d",&mx[i][j]);
     	}
     }    
}




void translate(squeeze_matrix *s,int m,int n,int(*matrix)[n])
{
	
	s->Row=m;
	s->Col=n;

	for (int i = 0; i <m ; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(matrix[i][j])
			{
				s->date[s->Num].row=i;
				s->date[s->Num].col=j;
				s->date[s->Num].value=matrix[i][j];
				s->Num ++;
			}
		}
	}
}




squeeze_matrix * transpose_way1(squeeze_matrix *s)
{
	squeeze_matrix *t;

	t=init();
	if(t)
	{
	    t->Row=s->Col;
	    t->Col=s->Row;
	    //t->Num=s->Num;

	    //core algorithm

	    for (int i = 0; i < s->Col; ++i)
	        {
	        	for (int j = 0; i < s->Num; ++j)
	        	{
	        		if(s->date[j].col==i)
	        		{
	        			t->date[t->Num].row=s->date[j].col;
	        			t->date[t->Num].col=s->date[j].row;
	        			t->date[t->Num].value=s->date[j].value;
	        			t->Num++;

	        			//s->date[j]->col=s->Col;
	        			
	        			if (t->Num >s->Num)
	        			{
	        				return t;
	        			}
	        		}
	        	}
	        } 


	}
	return NULL;
}





squeeze_matrix *transpose_way2(squeeze_matrix *s)
{
	squeeze_matrix *t;
	int min=0;
	t=init();
	t->Row=s->Row;
	t->Col=s->Col;

	for ( ;t->Num < s->Num; )
        {  
            for(int i=1;i<s->Num;i++)
                if(s->date[i].col < s->date[min].col)     min=i;
            t->date[t->Num].col=s->date[min].row;
            t->date[t->Num].row=s->date[min].col;
            t->Num ++;
            s->date[min].col =s->Col;
            
        }
       return t;
}



squeeze_matrix *transpose_way3(squeeze_matrix *s)
{
       int count[s->Col];
       int position[s->Col];
       squeeze_matrix *t=(squeeze_matrix*)malloc(sizeof(squeeze_matrix));
       t->Col=s->Row;
       t->Row=s->Col;
       t->Num=0;
      
       //step 1
       for(int i=0;i<s->Col;i++)         count[i]=0;
       for(int j=0;j<s->Num;j++)
       {
        count[ s->date[j].col ] ++;
       }        
       
       //step 2
       position[0]=1;
       for (int i = 1; i < s->Col; ++i)
       {
       	  position[i]=count[i-1]+position[i-1];
       }


       //step 3

       for (int i = 0; i < s->Num; ++i)
       {
       	   t->date[ position[s->date[i].col] ] .col=s->date[i].row;
       	   t->date[ position[s->date[i].col] ] .row=s->date[i].col;
       	   t->date[ position[s->date[i].col] ] .value=s->date[i].value;
       	   position[s->date[i].col] ++;

       }

       return t;
}


void  print_matrix(int m,int n,int(* a)[n])
{
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; i < n; ++j)
            printf("%d\n", a[i][j]);
        printf("\n");		
	}
}
  
  

void print_squ_matrix(squeeze_matrix * s)
{
	printf("the squeeze_matrix is:\n");
	for (int i = 0; i < s->Num; ++i)
		printf("%5d %5d  %5d\n", s->date[i].row,s->date[i].col,s->date[i].value);
}                  
                     
 
	    		
     










 














