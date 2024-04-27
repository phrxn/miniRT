#include "array_test.h"
#include "array.h"
#include "libft.h"

#include <stdlib.h>
#include <string.h>

#include "assertz.h"

static void ft_lstget_test()
{
	create_subtitle("ft_lstget_test");

	//test1: null;
	t_list *test1Head = NULL;

	t_list *test1Return1 = ft_lstget(test1Head, 0);
	t_list *test1Return2 = ft_lstget(test1Head, 1);

	assert_address(NULL, test1Return1, "test1Return1 ");
	assert_address(NULL, test1Return2, "test1Return2 ");
	assert_utils_separator();

	//test2: 1 items;
	t_list test2item1; test2item1.next = NULL;

	t_list *test2Return1 = ft_lstget(&test2item1, 0);
	t_list *test2Return2 = ft_lstget(&test2item1, 1);

	assert_address(&test2item1, test2Return1, "test2Return1 ");
	assert_address(NULL,        test2Return2, "test2Return2 ");
	assert_utils_separator();

	//test3: 2 items;

	t_list test3item2; test3item2.next = NULL;
	t_list test3item1; test3item1.next = &test3item2;

	t_list *test3Return1 = ft_lstget(&test3item1, 0);
	t_list *test3Return2 = ft_lstget(&test3item1, 1);
	t_list *test3Return3 = ft_lstget(&test3item1, 2);

	assert_address(&test3item1, test3Return1, "test3Return1 ");
	assert_address(&test3item2, test3Return2, "test3Return2 ");
	assert_address(NULL       , test3Return3, "test3Return3 ");
}

void swap_int(void *one, void *two)
{
	int *value1 = (int*) one;
	int *value2 = (int*) two;

	if (*value1 > *value2)
	{
		int temp = *value1;
		*value1 = *value2;
		*value2 = temp;
	}
}

static void	ft_lstsort_test()
{
	create_subtitle("ft_lstsort_test");

	//test1: null;
	t_list *test1Head = NULL;

	ft_lstsort(test1Head, swap_int);
	assert_utils_print_ok("test1Head");

	//test2: one item
	int value;
	t_list test2item1; test2item1.content = &value; test2item1.next = NULL;

	ft_lstsort(&test2item1, swap_int);
	assert_utils_print_ok("test2item1");
	assert_utils_separator();

	//test3: two items
	int value1 = 3, value2 = 5;
	t_list test31item2; test31item2.content = &value1; test31item2.next = NULL;
	t_list test31item1; test31item1.content = &value2; test31item1.next = &test31item2;

	assert_svalue(3, *(int*)(test31item2.content), "before sort: test31item2 == 3 ");
	assert_svalue(5, *(int*)(test31item1.content), "before sort: test31item1 == 5 ");

	ft_lstsort(&test2item1, swap_int);

	assert_svalue(3, *(int*)(test31item2.content), "after sort: test31item2 == 5 ");
	assert_svalue(5, *(int*)(test31item1.content), "after sort: test31item1 == 3 ");
	assert_utils_separator();

	//test4: three items
	int value41 = 7, value42 = 3, value43 = 5;

	t_list test41item3; test41item3.content = &value43; test41item3.next = NULL;
	t_list test41item2; test41item2.content = &value42; test41item2.next = &test41item3;
	t_list test41item1; test41item1.content = &value41; test41item1.next = &test41item2;

	assert_svalue(7, *(int*)(test41item1.content), "before sort: test41item1 == 7 ");
	assert_svalue(3, *(int*)(test41item2.content), "before sort: test41item2 == 3 ");
	assert_svalue(5, *(int*)(test41item3.content), "before sort: test41item3 == 5 ");

	ft_lstsort(&test41item1, swap_int);

	assert_svalue(3, *(int*)(test41item1.content), "after sort: test41item1 == 3 ");
	assert_svalue(5, *(int*)(test41item2.content), "after sort: test41item2 == 5 ");
	assert_svalue(7, *(int*)(test41item3.content), "after sort: test41item3 == 7 ");
	assert_utils_separator();

}


void array_test(int argc, char **argv)
{
	if (argc != 1 &&  strcmp(argv[1], "ray_test") != 0)
		return ;
	create_title("ray_test");

	ft_lstget_test();
	ft_lstsort_test();
}