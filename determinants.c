#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_INT_LEN 1024
int* removing(int dim, int* p, int row, int column)
{
	int new[dim-1][dim-1];
	int i;
	int j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			new[i][j]
		}
	}
}
int determinant_finder(int dim, int* p)
{
	int result;
	int i;
	int j;
	if(dim==2)
	{
		 result = *(p+(0*dim)+0) * *(p+(1*dim)+1) - (*(p+(dim*0)+1) * *(p+(dim*1)+0));
		 return result;
	}
	else
	{
		for(j=0;j<dim;j++)
		{
			determinant_finder(dim-1, p, 0, j); 
		}
	}
}
int get_matrix(int dim, int depth)
{
	int i;
	int j;
	int array[dim][dim];
	int result;
	if(depth == 0)
	{
		for(i=0;i<dim;i++)
		{
			for(j=0;j<dim;j++)
			{
				printf("Please enter the entry at index(%d, %d)\n", i, j);
				scanf("%d", &array[i][j]);
				getchar();
			}
		}
		printf("Your matrix is:\n");
		for(i=0;i<dim;i++)
		{
			for(j=0;j<dim;j++)
			{
				printf("%d ", array[i][j]);
			}
			printf("\n");
		}
	}
	
}
int main()
{
	//int array[3][3] = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
	int dim;
	printf("Please enter the number of columns/rows in the matrix. It must be a square matrix.\n");
	scanf("%d", &dim);
	getchar();
	get_matrix(dim);
	
	
}