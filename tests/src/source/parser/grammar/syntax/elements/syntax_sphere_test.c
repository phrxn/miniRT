#include "syntax_elements_test.h"
#include "syntax_elements.h"
#include "syntax_errors.h"

#include "assertz.h"
#include <string.h>

#include "token.h"

#include <libft.h>

void	syntax_sphere_test1()
{
	//test 1 valid syntax
	t_token test1Tokens[16];
	test1Tokens[ 0].text = "sp";    test1Tokens[ 0].type = identifier;
	test1Tokens[ 1].text = " ";     test1Tokens[ 1].type = separator_property;
	test1Tokens[ 2].text = "12";    test1Tokens[ 2].type = pos_int;
	test1Tokens[ 3].text = ",";     test1Tokens[ 3].type = separator_value;
	test1Tokens[ 4].text = "-78";   test1Tokens[ 4].type = neg_int;
	test1Tokens[ 5].text = ",";     test1Tokens[ 5].type = separator_value;
	test1Tokens[ 6].text = "-10";   test1Tokens[ 6].type = neg_int;
	test1Tokens[ 7].text = " ";     test1Tokens[ 7].type = separator_property;
	test1Tokens[ 8].text = "45.2";  test1Tokens[ 8].type = pos_double;
	test1Tokens[ 9].text = " ";     test1Tokens[ 9].type = separator_property;
	test1Tokens[10].text = "120";   test1Tokens[10].type = pos_int;
	test1Tokens[11].text = ",";     test1Tokens[11].type = separator_value;
	test1Tokens[12].text = "80";    test1Tokens[12].type = pos_int;
	test1Tokens[13].text = ",";     test1Tokens[13].type = separator_value;
	test1Tokens[14].text = "9";     test1Tokens[14].type = pos_int;
	test1Tokens[15].text = NULL;    test1Tokens[15].type = eol;

	t_list	test1List[16];
	test1List[ 0].content = &test1Tokens[ 0]; test1List[ 0].next = &test1List[ 1];
	test1List[ 1].content = &test1Tokens[ 1]; test1List[ 1].next = &test1List[ 2];
	test1List[ 2].content = &test1Tokens[ 2]; test1List[ 2].next = &test1List[ 3];
	test1List[ 3].content = &test1Tokens[ 3]; test1List[ 3].next = &test1List[ 4];
	test1List[ 4].content = &test1Tokens[ 4]; test1List[ 4].next = &test1List[ 5];
	test1List[ 5].content = &test1Tokens[ 5]; test1List[ 5].next = &test1List[ 6];
	test1List[ 6].content = &test1Tokens[ 6]; test1List[ 6].next = &test1List[ 7];
	test1List[ 7].content = &test1Tokens[ 7]; test1List[ 7].next = &test1List[ 8];
	test1List[ 8].content = &test1Tokens[ 8]; test1List[ 8].next = &test1List[ 9];
	test1List[ 9].content = &test1Tokens[ 9]; test1List[ 9].next = &test1List[10];
	test1List[10].content = &test1Tokens[10]; test1List[10].next = &test1List[11];
	test1List[11].content = &test1Tokens[11]; test1List[11].next = &test1List[12];
	test1List[12].content = &test1Tokens[12]; test1List[12].next = &test1List[13];
	test1List[13].content = &test1Tokens[13]; test1List[13].next = &test1List[14];
	test1List[14].content = &test1Tokens[14]; test1List[14].next = &test1List[15];
	test1List[15].content = &test1Tokens[15]; test1List[15].next = NULL;

	assert_svalue(OK_SYNTAX, syntax_sphere(test1List), "test 1 syntax valid");
}

void	syntax_sphere_test(int argc, char **argv)
{
	if (argc != 1 &&  strcmp(argv[1], "syntax_sphere_test") != 0)
		return ;
	create_title("syntax_sphere_test");

	syntax_sphere_test1();
}