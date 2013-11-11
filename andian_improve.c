#include <stdio.h>
#include <stdlib.h>
#define  m 3
#define  n 3



void input(int (*c)[n])
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




void find_max(int (*c)[n],int *col)
{ 
int max;
    

    for (int i = 0; i < n; ++i)
    {
      max=c[0][i];
      for (int j = 1;  j< m; ++j)
          if (c[j][i]>max)    
             max=c[j][i];
             
      col[i]=max;

    }
}





void find_min(int (*c)[n],int* row)
{
	int min;
	for (int i = 0; i < m; ++i)
	{
		min=c[i][0];
		for (int  j= 1; j < n; ++j)
             if(c[i][j]<min)      min=c[i][j];
        row[i]=min;
	}
}





void check(int (*c)[n],int *row,int *col)
{
  int count=0;
	printf("point that meet the standard is as follow:\n");
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n ;++j)
		{
			if(c[i][j]==row[i]&&c[i][j]==col[j])
      {
				printf("(%d,%d)----%d ",i,j,c[i][j]);
        count ++;
      }
		}
		//printf("\n");
	}
  if(count ==0)    printf("can not find such point!\n");

	printf("\n");
}





int main(int argc, char const *argv[])
{
    int matrix[m][n];
    int row[m];
    int col[n];

    input(matrix);
    find_min(matrix,row);
    find_max(matrix,col);
    check(matrix,row,col);
	  return 0;
}