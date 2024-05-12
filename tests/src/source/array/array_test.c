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

void swap_int(void **one, void **two)
{
	int value1 = **(int**) one;
	int value2 = **(int**) two;

	if (value2 < value1)
	{
		void *tmp = *one;
		*one = *two;
		*two = tmp;
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

	//test3.1: two items items already organized (smallest to largest)
	int value1 = 3, value2 = 5;
	t_list test31item2; test31item2.content = &value2; test31item2.next = NULL;
	t_list test31item1; test31item1.content = &value1; test31item1.next = &test31item2;

	assert_svalue(3, *(int*)(test31item1.content), "before sort: test31item1 == 3 ");
	assert_svalue(5, *(int*)(test31item2.content), "before sort: test31item2 == 5 ");

	ft_lstsort(&test31item1, swap_int);

	assert_svalue(3, *(int*)(test31item1.content), "after sort: test31item1 == 3 ");
	assert_svalue(5, *(int*)(test31item2.content), "after sort: test31item2 == 5 ");

	assert_utils_separator();

	//test3.2: two items items not organized
	int value32_1 = 5, value32_2 = 3;
	t_list test32item2; test32item2.content = &value32_2; test32item2.next = NULL;
	t_list test32item1; test32item1.content = &value32_1; test32item1.next = &test32item2;

	assert_svalue(5, *(int*)(test32item1.content), "before sort: test32item1 == 5 ");
	assert_svalue(3, *(int*)(test32item2.content), "before sort: test32item2 == 3 ");

	ft_lstsort(&test32item1, swap_int);

	assert_svalue(3, *(int*)(test32item1.content), "after sort: test32item1 == 3 ");
	assert_svalue(5, *(int*)(test32item2.content), "after sort: test32item2 == 5 ");

	assert_utils_separator();


	//test4.1: three items items already organized (smallest to largest)
	int value41 = 3, value42 = 5, value43 = 7;

	t_list test41item3; test41item3.content = &value43; test41item3.next = NULL;
	t_list test41item2; test41item2.content = &value42; test41item2.next = &test41item3;
	t_list test41item1; test41item1.content = &value41; test41item1.next = &test41item2;

	assert_svalue(3, *(int*)(test41item1.content), "before sort: test41item1 == 3 ");
	assert_svalue(5, *(int*)(test41item2.content), "before sort: test41item2 == 5 ");
	assert_svalue(7, *(int*)(test41item3.content), "before sort: test41item3 == 7 ");

	ft_lstsort(&test41item1, swap_int);

	assert_svalue(3, *(int*)(test41item1.content), "after sort: test41item1 == 3 ");
	assert_svalue(5, *(int*)(test41item2.content), "after sort: test41item2 == 5 ");
	assert_svalue(7, *(int*)(test41item3.content), "after sort: test41item3 == 7 ");
	assert_utils_separator();


	//test4.2: three items items not organized
	int value42_1 = 7, value42_2 = 3, value42_3 = 5;

	t_list test42item3; test42item3.content = &value42_3; test42item3.next = NULL;
	t_list test42item2; test42item2.content = &value42_2; test42item2.next = &test42item3;
	t_list test42item1; test42item1.content = &value42_1; test42item1.next = &test42item2;

	assert_svalue(7, *(int*)(test42item1.content), "before sort: test42item1 == 7 ");
	assert_svalue(3, *(int*)(test42item2.content), "before sort: test42item2 == 3 ");
	assert_svalue(5, *(int*)(test42item3.content), "before sort: test42item3 == 5 ");

	ft_lstsort(&test42item1, swap_int);

	assert_svalue(3, *(int*)(test42item1.content), "after sort: test42item1 == 3");
	assert_svalue(5, *(int*)(test42item2.content), "after sort: test42item2 == 5");
	assert_svalue(7, *(int*)(test42item3.content), "after sort: test42item3 == 7");
	assert_utils_separator();


	//test4.3: three items items not organized
	int test4_3value1 = 5, test4_3value2 = 3, test4_3value3 = 7;

	t_list test4_3item3; test4_3item3.content = &test4_3value3; test4_3item3.next = NULL;
	t_list test4_3item2; test4_3item2.content = &test4_3value2; test4_3item2.next = &test4_3item3;
	t_list test4_3item1; test4_3item1.content = &test4_3value1; test4_3item1.next = &test4_3item2;

	assert_svalue(5, *(int*)(test4_3item1.content), "before sort: test4_3item1 == 5");
	assert_svalue(3, *(int*)(test4_3item2.content), "before sort: test4_3item2 == 3");
	assert_svalue(7, *(int*)(test4_3item3.content), "before sort: test4_3item3 == 7");

	ft_lstsort(&test4_3item1, swap_int);

	assert_svalue(3, *(int*)(test4_3item1.content), "after sort: test4_3item1 == 3");
	assert_svalue(5, *(int*)(test4_3item2.content), "after sort: test4_3item2 == 5");
	assert_svalue(7, *(int*)(test4_3item3.content), "after sort: test4_3item3 == 7");
	assert_utils_separator();










}


void array_test(int argc, char **argv)
{
	if (argc != 1 &&  strcmp(argv[1], "array_test") != 0)
		return ;
	create_title("array_test");

	ft_lstget_test();
	ft_lstsort_test();
}