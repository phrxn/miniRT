#include "canvas_test.h"
#include "matrix_operations_test.h"
#include "matrix_test.h"
#include "matrix_fill_test.h"

int main(int argc, char *argv[])
{

	matrix_test(argc, argv);
	//matrix_operations_test(argc, argv);
	//canvas_test(argc, argv);
	matrix_fill_test(argc, argv);
	return 0;
}
