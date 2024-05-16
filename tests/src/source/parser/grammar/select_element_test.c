#include "select_element_test.h"
#include "select_element.h"
#include "token.h"

#include "assertz.h"
#include <string.h>


void	select_element_type_test()
{
	create_subtitle("select_element_type_test");

	//test1
	t_token test1Token; test1Token.text = "";
	assert_svalue(not_exist, select_element_type(&test1Token), "test1 not_exist");

	//test2
	t_token test2Token; test2Token.text = " ";
	assert_svalue(not_exist, select_element_type(&test2Token), "test2 not_exist");

	//test3
	t_token test3Token; test3Token.text = "   ";
	assert_svalue(not_exist, select_element_type(&test3Token), "test3 not_exist");

	//test4
	t_token test4Token; test4Token.text = "A";
	assert_svalue(ambient, select_element_type(&test4Token), "test4 ambient");

	//test5
	t_token test5Token; test5Token.text = "C";
	assert_svalue(camera, select_element_type(&test5Token), "test5 camera");

	//test6
	t_token test6Token; test6Token.text = "L";
	assert_svalue(light, select_element_type(&test6Token), "test6 light");

	//test7
	t_token test7Token; test7Token.text = "sp";
	assert_svalue(sphere, select_element_type(&test7Token), "test7 sphere");

	//test8
	t_token test8Token; test8Token.text = "pl";
	assert_svalue(plane, select_element_type(&test8Token), "test8 plane");

	//test9
	t_token test9Token; test9Token.text = "cy";
	assert_svalue(cylinder, select_element_type(&test9Token), "test9 cylinder");


}

void	select_element_test(int argc, char **argv)
{
	if (argc != 1 &&  strcmp(argv[1], "select_element_test") != 0)
		return ;
	create_title("select_element_test");

	select_element_type_test();
}