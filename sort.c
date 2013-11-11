#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  n   9


int  qpass(int *a,int low,int high)
{
	a[0]=a[1];
	while(low < high)
    {
    	while((low < high) && (a[high] > a[0]))   --high;
	    a[low]=a[high];
	    //low ++;
	    while((low < high) &&(a[low]< a[0]))      --low;
	    a[high]=a[low];
	}
	a[low]=a[0];
    return low;
}




void Qsort(int* a,int low,int high)
{

	 int  pos;
     if (low < high)
     {
     	pos =qpass(a,low,high);
     	Qsort(a,low,pos-1);
     	Qsort(a,pos+1,high);

     }
}




void dir_insert(int* a,int l)
{
	int i,j;
	for ( i = 2; i <=l; ++i)
	{
		if (a[i] > a[i-1])
		{

		a[0]=a[i];
		for ( j = i-1; a[i] < a[j] ; --j)
           a[j+1]=a[j];

        a[j+1]=a[0];

        }
	}
}




int main(int argc, char const *argv[])
{
	int a[n+1];
    for (int i = 1; i <=n; ++i)      scanf("%d",&a[i]);
//    Qsort(a,1,n);
    dir_insert(a,n);
    for (int i = 1; i <=n; ++i)      printf("%d  ",a[i]);
    printf("\n");
	return 0;
}
