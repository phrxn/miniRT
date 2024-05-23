#include "ft_atoi_2_test.h"
#include "ft_atoi_2.h"
#include "convert_errors.h"

#include "string.h"
#include "assertz.h"

void	ft_atoi_2_test1()
{
	create_subtitle("ft_atoi_2_test");

	//test1 over and under flow
	int	test1Status = 0;
	char *test1Str1 = "2147483648";
	char *test1Str2 = "-2147483649";
	char *test1Str3 = "2147483647";
	char *test1Str4 = "-2147483648";
	ft_atoi_2(test1Str1, &test1Status);
	assert_svalue(ERR_OVER_UNDER, test1Status, "test 1: 2147483648 overflow");
	ft_atoi_2(test1Str2, &test1Status);
	assert_svalue(ERR_OVER_UNDER, test1Status, "test 1: -2147483649 under");
	ft_atoi_2(test1Str3, &test1Status);
	assert_svalue(OK_CONVERT, test1Status, "test 1: 2147483647 under");
	ft_atoi_2(test1Str4, &test1Status);
	assert_svalue(OK_CONVERT, test1Status, "test 1: -2147483648 under");
}

void	ft_atoi_2_test(int argc, char **argv)
{
	if (argc != 1 &&  strcmp(argv[1], "ft_atoi_2_test") != 0)
		return ;
	create_title("ft_atoi_2_test");
	ft_atoi_2_test1();
}