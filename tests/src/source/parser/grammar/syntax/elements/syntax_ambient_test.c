#include "syntax_elements_test.h"
#include "syntax_elements.h"
#include "syntax_errors.h"

#include "assertz.h"
#include <string.h>

#include "token.h"

#include <libft.h>

static void syntax_ambient_test1()
{
	//test 1
	t_token test1Tokens[10];
	test1Tokens[0].text = "A";   test1Tokens[0].type = identifier;
	test1Tokens[1].text = " ";   test1Tokens[1].type = separator_property;
	test1Tokens[2].text = "0.4"; test1Tokens[2].type = pos_double;
	test1Tokens[3].text = " ";   test1Tokens[3].type = separator_property;
	test1Tokens[4].text = "39";  test1Tokens[4].type = pos_int;
	test1Tokens[5].text = ",";   test1Tokens[5].type = separator_value;
	test1Tokens[6].text = "40";  test1Tokens[6].type = pos_int;
	test1Tokens[7].text = ",";   test1Tokens[7].type = separator_value;
	test1Tokens[8].text = "45";  test1Tokens[8].type = pos_int;
	test1Tokens[9].text = NULL;  test1Tokens[9].type = eol;

	t_list	test1List[10];
	test1List[0].content = &test1Tokens[0]; test1List[0].next = &test1List[1];
	test1List[1].content = &test1Tokens[1]; test1List[1].next = &test1List[2];
	test1List[2].content = &test1Tokens[2]; test1List[2].next = &test1List[3];
	test1List[3].content = &test1Tokens[3]; test1List[3].next = &test1List[4];
	test1List[4].content = &test1Tokens[4]; test1List[4].next = &test1List[5];
	test1List[5].content = &test1Tokens[5]; test1List[5].next = &test1List[6];
	test1List[6].content = &test1Tokens[6]; test1List[6].next = &test1List[7];
	test1List[7].content = &test1Tokens[7]; test1List[7].next = &test1List[8];
	test1List[8].content = &test1Tokens[8]; test1List[8].next = &test1List[9];
	test1List[9].content = &test1Tokens[9]; test1List[9].next = NULL;

	assert_svalue(OK_SYNTAX, syntax_ambient(test1List), "test 1 valid syntax");
}

void	syntax_ambient_test(int argc, char **argv)
{
	if (argc != 1 &&  strcmp(argv[1], "syntax_ambient_test") != 0)
		return ;
	create_title("syntax_ambient_test");

	syntax_ambient_test1();
}
