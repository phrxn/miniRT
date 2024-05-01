#include "hit_test.h"
#include "hit.h"
#include "assertz.h"
#include "intersect.h"
#include "intersect_utils.h"

#include <string.h>

static void hit1_test()
{
	create_subtitle(" hit1_test");

	t_shape fakeShape;

	// test1 -> NULL
	t_inter *test1TheHit = hit(NULL);
	assert_address(NULL, test1TheHit, "test1 NULL");

	// test2 -> 1 negative
	t_inter *test2Inter1 = create_intersection(-1, &fakeShape);
	t_list  *test2Item1  = ft_lstnew(test2Inter1);
	t_inter *test2TheHit = hit(test2Item1);

	assert_address(NULL, test1TheHit, "test2 one negative value");
	ft_lstclear(&test2Item1, destroy_intersection2);
	assert_utils_separator();

	// test3 -> 2 negative
	t_inter *test3Inter1 = create_intersection(-1, &fakeShape);
	t_inter *test3Inter2 = create_intersection(-2, &fakeShape);
	t_list  *test3Item1  = ft_lstnew(test3Inter1);
	t_list  *test3Item2  = ft_lstnew(test3Inter2);
	test3Item1->next =test3Item2;
	t_inter *test3TheHit = hit(test3Item1);

	assert_address(NULL, test1TheHit, "test3 one negative value");
	ft_lstclear(&test3Item1, destroy_intersection2);
	assert_utils_separator();

	// test4 -> 2 positive
	t_inter *test4Inter1 = create_intersection(2, &fakeShape);
	t_inter *test4Inter2 = create_intersection(1, &fakeShape);
	t_list  *test4Item1  = ft_lstnew(test4Inter1);
	t_list  *test4Item2  = ft_lstnew(test4Inter2);
	test4Item1->next =test4Item2;
	t_inter *test4TheHit = hit(test4Item1);

	assert_address(test4TheHit, test4Inter2, "test4 valid T");
	ft_lstclear(&test4Item1, destroy_intersection2);
	assert_utils_separator();

	// test5 -> 2 positive
	t_inter *test5Inter1 = create_intersection(2, &fakeShape);
	t_inter *test5Inter2 = create_intersection(-1, &fakeShape);
	t_inter *test5Inter3 = create_intersection(1, &fakeShape);
	t_inter *test5Inter4 = create_intersection(7, &fakeShape);
	t_list  *test5Item1  = ft_lstnew(test5Inter1);
	t_list  *test5Item2  = ft_lstnew(test5Inter2);
	t_list  *test5Item3  = ft_lstnew(test5Inter3);
	t_list  *test5Item4  = ft_lstnew(test5Inter4);
	test5Item1->next =test5Item2;
	test5Item2->next =test5Item3;
	test5Item3->next =test5Item4;
	t_inter *test5TheHit = hit(test5Item1);

	assert_address(test5TheHit, test5Inter3, "test5 valid T");
	ft_lstclear(&test5Item1, destroy_intersection2);
}



void	hit_test(int argc, char **argv)
{
	if (argc != 1 &&  strcmp(argv[1], "hit_test") != 0)
		return ;

	hit1_test();

}