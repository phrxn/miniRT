#include "print_matrix.h"
#include <stdio.h>

void print_matrix(t_matrix *to_print, int detalhed)
{

	unsigned int last_col = to_print->cols - 1;
	size_t matrix_size = to_print->rows * to_print->cols;

	printf("rows: %d, cols: %d\n", to_print->rows, to_print->cols);
	for (int count = 0; count < matrix_size; count++)
	{
		double element = to_print->elements[count];
		if (detalhed)
			printf("%100.90f", element);
		else
			printf("%10.5f", element);

		if ((count % to_print->cols) == last_col)
			printf("\n");
		else
			printf(" | ");
	}
}