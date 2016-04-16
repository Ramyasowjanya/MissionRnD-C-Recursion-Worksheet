/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

void spiral_print(int x, int y, int round, int rows, int columns, int **input_array, int *arr, int *index, int max)
{
	if (*index < max)
	{
		arr[*index] = input_array[x][y];
		(*index)++;
		//printf("%d ",arr[*index-1]);
		if (x == round&&y < columns - 1)
		{
			++y;
			spiral_print(x, y, round, rows, columns, input_array, arr, index, max);
		}
		else if (y == columns - 1 && x<rows - 1)
		{
			++x;
			spiral_print(x, y, round, rows, columns, input_array, arr, index, max);
		}
		else if (x == rows - 1 && y>round)
		{
			--y;
			spiral_print(x, y, round, rows, columns, input_array, arr, index, max);
		}
		else if (x == round + 1 && y == round)
		{
			round++; y++; rows--;
			columns--;
			spiral_print(x, y, round, rows, columns, input_array, arr, index, max);
		}
		else
		{
			--x;
			spiral_print(x, y, round, rows, columns, input_array, arr, index, max);
		}

	}
}
int *spiral(int rows, int columns, int **input_array)
{
	int index = 0, *spiral_arr, max = rows*columns;
	if (input_array != NULL&&rows>0 && columns>0)
	{
		spiral_arr = (int*)malloc(rows*columns*sizeof(int));
		spiral_print(0, 0, 0, rows, columns, input_array, spiral_arr, &index, max);
		return spiral_arr;
	}
	return NULL;
}
