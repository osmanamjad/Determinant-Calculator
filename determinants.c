#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_INT_LEN 1024
int** remove_column(int dim, int column, int** array3)
{
    int** small = malloc(dim*sizeof(int*));
    for(int i=0;i<dim;i++)
    {
        small[i] = malloc(dim*sizeof(int));
    }
	for(int i=0;i<dim-1;i++)
	{
	    int j;
		for(j=0;j<column;j++)
		{
			small[i][j] = array3[i+1][j];
		}
		for(j=column;j<dim-1;j++)
        {
            small[i][j] = array3[i+1][j+1];
		}
	}
	return small;
}
int find_determinant(int dim, int** array2)
{
	int result = 0;
	if(dim==2)
	{
		 return (array2[0][0] * array2[1][1]) - (array2[0][1] * array2[1][0]);
	}
	else
	{
	    int j;
		for(j=0;j<dim;j++)
		{
			result += pow(-1, j) * array2[0][j] * find_determinant(dim-1, remove_column(dim, j, array2));
		}
	}
	free(*array2);
	free(array2);
	return result;
}
int** get_matrix(int dim)
{
	int i;
	int j;
    int** array = malloc(dim*sizeof(int*));
    for(i=0;i<dim;i++)
    {
        array[i] = malloc(dim*sizeof(int));
    }
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
	return array;
}
int main()
{
	int dim;
	printf("Please enter the number of columns/rows in the matrix. It must be a square matrix.\n");
	scanf("%d", &dim);
	getchar();
	printf("%d", find_determinant(dim, get_matrix(dim)));

}
