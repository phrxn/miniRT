#include "matrix_test.h"
#include "matrix.h"
#include "string.h"

#include "../../assertz/assertz.h"

static int count_malloc = 0;
static int count_ft_calloc = 0;
static int count_free = 0;

t_matrix malloc_1;
t_matrix malloc_1_to_destroy;
double matrix_elements[4] = {1,2,3,4};


t_matrix malloc_2_to_destroy;
double matrix_elements_2_to_destroy[4] = {1,2,3,4};

void *malloc_mock_matrix(size_t size){
	if (count_malloc == 0)
	{
		count_malloc++;
		return NULL;
	}
	if (count_malloc == 1)
	{
		count_malloc++;
		return &malloc_1;
	}
	if (count_malloc == 2)
	{
		count_malloc++;
		return &malloc_1;
	}
	return NULL;
}

void *ft_calloc_mock_matrix(size_t nitems, size_t size)
{

	if (count_ft_calloc == 0)
	{
		count_ft_calloc++;
		return NULL;
	}
	if (count_ft_calloc == 1)
	{
		count_ft_calloc++;
		return matrix_elements;
	}
	return NULL;
}

void free_mock_matrix(void *freez)
{
	if (count_free == 0)
	{
		count_free++;
		return ;
	}
	if (count_free == 1)
	{
		count_free++;
		assert_address(&malloc_1_to_destroy, freez, "free_mock_matrix free->malloc_1_to_destroy");
		return ;
	}
	if (count_free == 2)
	{
		count_free++;
		assert_address(&matrix_elements_2_to_destroy, freez, "free_mock_matrix free->matrix_elements_2_to_destroy");
		return ;
	}
	if (count_free == 3)
	{
		count_free++;
		assert_address(&malloc_2_to_destroy, freez, "free_mock_matrix free->malloc_2_to_destroy");
		return ;
	}
}








static void	get_element_test()
{
	create_subtitle("get_element_test");

	//test 1 matrix 1x1
	double matrix_1_1_elements[1]; matrix_1_1_elements[0]= 2;
	t_matrix matrix_1_1; matrix_1_1.rows = 1; matrix_1_1.cols = 1; matrix_1_1.elements = matrix_1_1_elements;
	double valor1 =  get_element(&matrix_1_1, 0, 0);
	assert_svalue(2, valor1, "get_element matrix 1x1");

	//test 1 matrix 2x1
	double matrix_2_1_elements[2]; matrix_2_1_elements[0]= -8; matrix_2_1_elements[1]= 7;
	t_matrix matrix_2_1; matrix_2_1.rows = 2; matrix_2_1.cols = 1; matrix_2_1.elements = matrix_2_1_elements;
	double valor2 =  get_element(&matrix_2_1, 0, 0);
	assert_svalue(-8, valor2, "get_element matrix 2x1 element -8");
	double valor3 =  get_element(&matrix_2_1, 1, 0);
	assert_svalue(7, valor3, "get_element matrix 2x1 element 7");

	//test 1 matrix 1x2
	double matrix_1_2_elements[2]; matrix_1_2_elements[0]= 15; matrix_1_2_elements[1]= 42;
	t_matrix matrix_1_2; matrix_1_2.rows = 1; matrix_1_2.cols = 2; matrix_1_2.elements = matrix_1_2_elements;
	double valor4 =  get_element(&matrix_1_2, 0, 0);
	assert_svalue(15, valor4, "get_element matrix 1x2 element 15");
	double valor5 =  get_element(&matrix_1_2, 0, 1);
	assert_svalue(42, valor5, "get_element matrix 1x2 element 42");

	//test 1 matrix 2x2
	double matrix_2_2_elements[4]; matrix_2_2_elements[0]= 100; matrix_2_2_elements[1]= 200;
	                               matrix_2_2_elements[2]= 300; matrix_2_2_elements[3]= 400;
	t_matrix matrix_2_2; matrix_2_2.rows = 2; matrix_2_2.cols = 2; matrix_2_2.elements = matrix_2_2_elements;
	double valor6 =  get_element(&matrix_2_2, 0, 0);
	assert_svalue(100, valor6, "get_element matrix 2x2 element 100");
	double valor7 =  get_element(&matrix_2_2, 0, 1);
	assert_svalue(200, valor7, "get_element matrix 2x2 element 200");
	double valor8 =  get_element(&matrix_2_2, 1, 0);
	assert_svalue(300, valor8, "get_element matrix 2x2 element 300");
	double valor9 =  get_element(&matrix_2_2, 1, 1);
	assert_svalue(400, valor9, "get_element matrix 2x2 element 400");


}

static void	set_element_test()
{
	create_subtitle("set_element_test");

	//test 1 matrix 1x1
	double matrix_1_1_elements[1]; matrix_1_1_elements[0]= 0;
	t_matrix matrix_1_1; matrix_1_1.rows = 1; matrix_1_1.cols = 1; matrix_1_1.elements = matrix_1_1_elements;
	set_element(&matrix_1_1, 0, 0, 42);
	assert_svalue(42, matrix_1_1_elements[0], "set_element matrix 1x1");

	//test 2 matrix 1x2
	double matrix_1_2_elements[2]; matrix_1_2_elements[0]= 0; matrix_1_2_elements[1]= 0;
	t_matrix matrix_1_2; matrix_1_2.rows = 1; matrix_1_2.cols = 2; matrix_1_2.elements = matrix_1_2_elements;
	set_element(&matrix_1_2, 0, 0, 70);
	set_element(&matrix_1_2, 0, 1, 100);
	assert_svalue(70, matrix_1_2_elements[0], "set_element matrix 1x2");
	assert_svalue(100, matrix_1_2_elements[1], "set_element matrix 1x2");

	//test 3 matrix 2x1
	double matrix_2_1_elements[2]; matrix_2_1_elements[0]= 0; matrix_2_1_elements[1]= 0;
	t_matrix matrix_2_1; matrix_2_1.rows = 2; matrix_2_1.cols = 1; matrix_2_1.elements = matrix_2_1_elements;
	set_element(&matrix_2_1, 0, 0, 60);
	set_element(&matrix_2_1, 1, 0, 200);
	assert_svalue(60, matrix_2_1_elements[0], "set_element matrix 2x1");
	assert_svalue(200, matrix_2_1_elements[1], "set_element matrix 2x1");

	//test 4 matrix 2x2
	double matrix_2_2_elements[4] = {0, 0, 0, 0};
	t_matrix matrix_2_2; matrix_2_2.rows = 2; matrix_2_2.cols = 2; matrix_2_2.elements = matrix_2_2_elements;
	set_element(&matrix_2_2, 0, 0, 55);
	set_element(&matrix_2_2, 0, 1, 18);
	set_element(&matrix_2_2, 1, 0, 253);
	set_element(&matrix_2_2, 1, 1, 33);
	assert_svalue(55, matrix_2_2_elements[0], "set_element matrix 2x2");
	assert_svalue(18, matrix_2_2_elements[1], "set_element matrix 2x2");
	assert_svalue(253, matrix_2_2_elements[2], "set_element matrix 2x2");
	assert_svalue(33, matrix_2_2_elements[3], "set_element matrix 2x2");
}

void create_matrix_test()
{
	create_subtitle("create_matrix_test");

    //must be free
	t_matrix *must_be_null = create_matrix(3,3);
	assert_address(NULL, must_be_null, "must_be_null ");

	//erro ft_calloc
	t_matrix *error_ft_calloc = create_matrix(3,3);
	assert_address(NULL, error_ft_calloc, "error_ft_calloc ");

	//all ok
	t_matrix *all_ok_matrix = create_matrix(2,2);
	assert_address(&malloc_1, all_ok_matrix, "all_ok_matrix matrix");
	assert_address(matrix_elements, all_ok_matrix->elements, "all_ok_matrix elements address");
}

void destroy_matrix_test()
{
	create_subtitle("destroy_matrix_test");

	//all null
	destroy_matrix(NULL);

	t_matrix *null_point = NULL;
	destroy_matrix(&null_point);

	//valid matrix, but invalid element address(NULL)
	t_matrix *valid_matrix = &malloc_1_to_destroy;
	destroy_matrix(&valid_matrix);
	assert_address(NULL, valid_matrix, "destroy_matrix_test valid_matrix");


	//valid matrix with valid element address
	t_matrix *valid_matrix2 = &malloc_2_to_destroy;
	valid_matrix2->elements = matrix_elements_2_to_destroy;
	destroy_matrix(&valid_matrix2);
	assert_address(NULL, valid_matrix2, "destroy_matrix_test valid_matrix2");








	assert_utils_print_ok("destroy_matrix ok");
}

void matrix_test(int argc, char **argv)
{

	if (argc != 1 &&  strcmp(argv[1], "matrix_test") != 0)
		return ;

	create_title("matrix_test");

	get_element_test();
	set_element_test();
	create_matrix_test();
	destroy_matrix_test();

}

#undef malloc_mock_matrix