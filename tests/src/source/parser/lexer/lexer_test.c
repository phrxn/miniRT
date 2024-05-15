#define _GNU_SOURCE
#include "lexer_test.h"
#include "lexer.h"
#include "line.h"
#include "token.h"

#include "libft.h"

#include "assertz.h"
#include <string.h>

#include "compare.h"


// fd in memory

#include <stdint.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "array.h"

static void	prepared_line_test()
{
	create_subtitle("prepared_line_test");

	//test 1
	char *test1Line = prepared_line(NULL);
	assert_address(NULL, test1Line, "test1");

	//test 2
	char *test2Line = prepared_line("");
	assert_address(NULL, test2Line, "test2");

	//test 3
	char *test3Line = prepared_line("\n");
	assert_address(NULL, test3Line, "test3");

	//test 4
	char *test4Line = prepared_line(" ");
	assert_address(NULL, test4Line, "test4");

	//test 5
	char *test5Line = prepared_line(" \n");
	assert_address(NULL, test5Line, "test5");

	//test 6
	char *test6Line = prepared_line("a");
	assert_svalue(1, (test6Line[0] == 'a' && test6Line[1] == '\0'), "test6");
	free(test6Line);

	//test 7
	char *test7Line = prepared_line("a\n");
	assert_svalue(1, (test7Line[0] == 'a' && test7Line[1] == '\0'), "test7");
	free(test7Line);

	//test 8.1 trim
	char *test8_1Line = prepared_line("  a\n");
	assert_svalue(1, (test8_1Line[0] == 'a' && test8_1Line[1] == '\0'), "test8_1");
	free(test8_1Line);

	//test 8.2 trim
	char *test8_2Line = prepared_line("  a");
	assert_svalue(1, (test8_2Line[0] == 'a' && test8_2Line[1] == '\0'), "test8_2");
	free(test8_2Line);

	//test 8.3 trim
	char *test8_3Line = prepared_line("a  \n");
	assert_svalue(1, (test8_3Line[0] == 'a' && test8_3Line[1] == '\0'), "test8_3");
	free(test8_3Line);

	//test 8.4 trim
	char *test8_4Line = prepared_line("a  ");
	assert_svalue(1, (test8_4Line[0] == 'a' && test8_4Line[1] == '\0'), "test8_4");
	free(test8_4Line);

	//test 8.5 trim
	char *test8_5Line = prepared_line("  a  \n");
	assert_svalue(1, (test8_5Line[0] == 'a' && test8_5Line[1] == '\0'), "test8_5");
	free(test8_5Line);

	//test 8.7 trim
	char *test8_7Line = prepared_line("  a  ");
	assert_svalue(1, (test8_7Line[0] == 'a' && test8_7Line[1] == '\0'), "test8_7");
	free(test8_7Line);
}

static void	line_create_tokens_test()
{
	create_subtitle("line_create_tokens_test");

	//test1
	char	*test1Line = "abc123";
	t_list 	*test1List = line_create_tokens(test1Line);
	t_token	test1TokenExpected1; test1TokenExpected1.text = "abc123"; test1TokenExpected1.type = identifier;
	t_token	test1TokenExpected2; test1TokenExpected2.text = NULL;    test1TokenExpected2.type = eol;
	assert_svalue(0, compare_token(&test1TokenExpected1, (t_token*)ft_lstget(test1List, 0)->content), "test1 token identifier (abc123)");
	assert_svalue(0, compare_token(&test1TokenExpected2, (t_token*)ft_lstget(test1List, 1)->content), "test1 token eol");
	assert_address(NULL, test1List->next->next, "test1 token eol->next");
	ft_lstclear(&test1List, destroy_token2);
	assert_utils_separator();

	//test 2.1 pos_int
	char	*test2_1Line = "123";
	t_list 	*test2_1List = line_create_tokens(test2_1Line);
	t_token	test2_1TokenExpected1; test2_1TokenExpected1.text = "123"; test2_1TokenExpected1.type = pos_int;
	t_token	test2_1TokenExpected2; test2_1TokenExpected2.text = NULL;    test2_1TokenExpected2.type = eol;
	assert_svalue(0, compare_token(&test2_1TokenExpected1, (t_token*)ft_lstget(test2_1List, 0)->content), "test2_1 token pos_int (123)");
	assert_svalue(0, compare_token(&test2_1TokenExpected2, (t_token*)ft_lstget(test2_1List, 1)->content), "test2_1 token eol");
	assert_address(NULL, test2_1List->next->next, "test2_1 token eol->next");
	ft_lstclear(&test2_1List, destroy_token2);
	assert_utils_separator();

	//test 2.2 pos_int
	char	*test2_2Line = "+123";
	t_list 	*test2_2List = line_create_tokens(test2_2Line);
	t_token	test2_2TokenExpected1; test2_2TokenExpected1.text = "+123"; test2_2TokenExpected1.type = pos_int;
	t_token	test2_2TokenExpected2; test2_2TokenExpected2.text = NULL;    test2_2TokenExpected2.type = eol;
	assert_svalue(0, compare_token(&test2_2TokenExpected1, (t_token*)ft_lstget(test2_2List, 0)->content), "test2_2 token pos_int (+123)");
	assert_svalue(0, compare_token(&test2_2TokenExpected2, (t_token*)ft_lstget(test2_2List, 1)->content), "test2_2 token eol");
	assert_address(NULL, test2_2List->next->next, "test2_2 token eol->next");
	ft_lstclear(&test2_2List, destroy_token2);
	assert_utils_separator();

	//test 2.3 pos_int
	char	*test2_3Line = "++123";
	t_list 	*test2_3List = line_create_tokens(test2_3Line);
	t_token	test2_3TokenExpected1; test2_3TokenExpected1.text = "++123"; test2_3TokenExpected1.type = identifier;
	t_token	test2_3TokenExpected2; test2_3TokenExpected2.text = NULL;    test2_3TokenExpected2.type = eol;
	assert_svalue(0, compare_token(&test2_3TokenExpected1, (t_token*)ft_lstget(test2_3List, 0)->content), "test2_3 token identifier (++123)");
	assert_svalue(0, compare_token(&test2_3TokenExpected2, (t_token*)ft_lstget(test2_3List, 1)->content), "test2_3 token eol");
	assert_address(NULL, test2_3List->next->next, "test2_3 token eol->next");
	ft_lstclear(&test2_3List, destroy_token2);
	assert_utils_separator();


	//test 3.1 neg_int
	char	*test3_1Line = "-123";
	t_list 	*test3_1List = line_create_tokens(test3_1Line);
	t_token	test3_1TokenExpected1; test3_1TokenExpected1.text = "-123"; test3_1TokenExpected1.type = neg_int;
	t_token	test3_1TokenExpected2; test3_1TokenExpected2.text = NULL;    test3_1TokenExpected2.type = eol;
	assert_svalue(0, compare_token(&test3_1TokenExpected1, (t_token*)ft_lstget(test3_1List, 0)->content), "test3_1 token neg_int (-123)");
	assert_svalue(0, compare_token(&test3_1TokenExpected2, (t_token*)ft_lstget(test3_1List, 1)->content), "test3_1 token eol");
	assert_address(NULL, test3_1List->next->next, "test3_1 token eol->next");
	ft_lstclear(&test3_1List, destroy_token2);
	assert_utils_separator();

	//test 3.2 neg_int
	char	*test3_2Line = "--123";
	t_list 	*test3_2List = line_create_tokens(test3_2Line);
	t_token	test3_2TokenExpected1; test3_2TokenExpected1.text = "--123"; test3_2TokenExpected1.type = identifier;
	t_token	test3_2TokenExpected2; test3_2TokenExpected2.text = NULL;    test3_2TokenExpected2.type = eol;
	assert_svalue(0, compare_token(&test3_2TokenExpected1, (t_token*)ft_lstget(test3_2List, 0)->content), "test3_2 token identifier (--123)");
	assert_svalue(0, compare_token(&test3_2TokenExpected2, (t_token*)ft_lstget(test3_2List, 1)->content), "test3_2 token eol");
	assert_address(NULL, test3_2List->next->next, "test3_2 token eol->next");
	ft_lstclear(&test3_2List, destroy_token2);
	assert_utils_separator();

	//test 4.1 pos_double
	char	*test4_1Line = "123.0";
	t_list 	*test4_1List = line_create_tokens(test4_1Line);
	t_token	test4_1TokenExpected1; test4_1TokenExpected1.text = "123.0"; test4_1TokenExpected1.type = pos_double;
	t_token	test4_1TokenExpected2; test4_1TokenExpected2.text = NULL;    test4_1TokenExpected2.type = eol;
	assert_svalue(0, compare_token(&test4_1TokenExpected1, (t_token*)ft_lstget(test4_1List, 0)->content), "test4_1 token identifier (123.0)");
	assert_svalue(0, compare_token(&test4_1TokenExpected2, (t_token*)ft_lstget(test4_1List, 1)->content), "test4_1 token eol");
	assert_address(NULL, test4_1List->next->next, "test4_1 token eol->next");
	ft_lstclear(&test4_1List, destroy_token2);
	assert_utils_separator();

	//test 4.2 pos_double
	char	*test4_2Line = "+123.0";
	t_list 	*test4_2List = line_create_tokens(test4_2Line);
	t_token	test4_2TokenExpected1; test4_2TokenExpected1.text = "+123.0"; test4_2TokenExpected1.type = pos_double;
	t_token	test4_2TokenExpected2; test4_2TokenExpected2.text = NULL;    test4_2TokenExpected2.type = eol;
	assert_svalue(0, compare_token(&test4_2TokenExpected1, (t_token*)ft_lstget(test4_2List, 0)->content), "test4_2 token identifier (+123.0)");
	assert_svalue(0, compare_token(&test4_2TokenExpected2, (t_token*)ft_lstget(test4_2List, 1)->content), "test4_2 token eol");
	assert_address(NULL, test4_2List->next->next, "test4_2 token eol->next");
	ft_lstclear(&test4_2List, destroy_token2);
	assert_utils_separator();

	//test 4.3 identifier
	char	*test4_3Line = "++123.0";
	t_list 	*test4_3List = line_create_tokens(test4_3Line);
	t_token	test4_3TokenExpected1; test4_3TokenExpected1.text = "++123.0"; test4_3TokenExpected1.type = identifier;
	t_token	test4_3TokenExpected2; test4_3TokenExpected2.text = NULL;    test4_3TokenExpected2.type = eol;
	assert_svalue(0, compare_token(&test4_3TokenExpected1, (t_token*)ft_lstget(test4_3List, 0)->content), "test4_3 token identifier (++123.0)");
	assert_svalue(0, compare_token(&test4_3TokenExpected2, (t_token*)ft_lstget(test4_3List, 1)->content), "test4_3 token eol");
	assert_address(NULL, test4_3List->next->next, "test4_3 token eol->next");
	ft_lstclear(&test4_3List, destroy_token2);
	assert_utils_separator();

	//test 5.1 identifier
	char	*test5_1Line = "-123.0";
	t_list 	*test5_1List = line_create_tokens(test5_1Line);
	t_token	test5_1TokenExpected1; test5_1TokenExpected1.text = "-123.0"; test5_1TokenExpected1.type = neg_double;
	t_token	test5_1TokenExpected2; test5_1TokenExpected2.text = NULL;    test5_1TokenExpected2.type = eol;
	assert_svalue(0, compare_token(&test5_1TokenExpected1, (t_token*)ft_lstget(test5_1List, 0)->content), "test5_1 token identifier (-123.0)");
	assert_svalue(0, compare_token(&test5_1TokenExpected2, (t_token*)ft_lstget(test5_1List, 1)->content), "test5_1 token eol");
	assert_address(NULL, test5_1List->next->next, "test5_1 token eol->next");
	ft_lstclear(&test5_1List, destroy_token2);
	assert_utils_separator();

	//test 5.1 identifier
	char	*test5_2Line = "--123.0";
	t_list 	*test5_2List = line_create_tokens(test5_2Line);
	t_token	test5_2TokenExpected1; test5_2TokenExpected1.text = "--123.0"; test5_2TokenExpected1.type = identifier;
	t_token	test5_2TokenExpected2; test5_2TokenExpected2.text = NULL;    test5_2TokenExpected2.type = eol;
	assert_svalue(0, compare_token(&test5_2TokenExpected1, (t_token*)ft_lstget(test5_2List, 0)->content), "test5_2 token identifier (--123.0)");
	assert_svalue(0, compare_token(&test5_2TokenExpected2, (t_token*)ft_lstget(test5_2List, 1)->content), "test5_2 token eol");
	assert_address(NULL, test5_2List->next->next, "test5_2 token eol->next");
	ft_lstclear(&test5_2List, destroy_token2);
	assert_utils_separator();

	//test 6.1 separator_property (one separator)
	char	*test6_1Line = " ";
	t_list 	*test6_1List = line_create_tokens(test6_1Line);
	t_token	test6_1TokenExpected1; test6_1TokenExpected1.text = " "; test6_1TokenExpected1.type = separator_property;
	t_token	test6_1TokenExpected2; test6_1TokenExpected2.text = NULL;    test6_1TokenExpected2.type = eol;
	assert_svalue(0, compare_token(&test6_1TokenExpected1, (t_token*)ft_lstget(test6_1List, 0)->content), "test6_1 token identifier ( )");
	assert_svalue(0, compare_token(&test6_1TokenExpected2, (t_token*)ft_lstget(test6_1List, 1)->content), "test6_1 token eol");
	assert_address(NULL, test6_1List->next->next, "test6_1 token eol->next");
	ft_lstclear(&test6_1List, destroy_token2);
	assert_utils_separator();

	//test 6.1 separator_property (one separator)
	char	*test6_2Line = "   ";
	t_list 	*test6_2List = line_create_tokens(test6_2Line);
	t_token	test6_2TokenExpected1; test6_2TokenExpected1.text = "   "; test6_2TokenExpected1.type = separator_property;
	t_token	test6_2TokenExpected2; test6_2TokenExpected2.text = NULL;    test6_2TokenExpected2.type = eol;
	assert_svalue(0, compare_token(&test6_2TokenExpected1, (t_token*)ft_lstget(test6_2List, 0)->content), "test6_2 token identifier (    )");
	assert_svalue(0, compare_token(&test6_2TokenExpected2, (t_token*)ft_lstget(test6_2List, 1)->content), "test6_2 token eol");
	assert_address(NULL, test6_2List->next->next, "test6_2 token eol->next");
	ft_lstclear(&test6_2List, destroy_token2);
	assert_utils_separator();

	//test 7.1 separator_property (one separator)
	char	*test7_1Line = ",";
	t_list 	*test7_1List = line_create_tokens(test7_1Line);
	t_token	test7_1TokenExpected1; test7_1TokenExpected1.text = NULL;  test7_1TokenExpected1.type = separator_value;
	t_token	test7_1TokenExpected2; test7_1TokenExpected2.text = NULL; test7_1TokenExpected2.type = eol;
	assert_svalue(0, compare_token(&test7_1TokenExpected1, (t_token*)ft_lstget(test7_1List, 0)->content), "test7_1 token identifier (,)");
	assert_svalue(0, compare_token(&test7_1TokenExpected2, (t_token*)ft_lstget(test7_1List, 1)->content), "test7_1 token eol");
	assert_address(NULL, test7_1List->next->next, "test7_1 token eol->next");
	ft_lstclear(&test7_1List, destroy_token2);
	assert_utils_separator();

	//test 7.2 separator_property (one separator)
	char	*test7_2Line = ",,";
	t_list 	*test7_2List = line_create_tokens(test7_2Line);
	t_token	test7_2TokenExpected1; test7_2TokenExpected1.text = NULL; test7_2TokenExpected1.type = separator_value;
	t_token	test7_2TokenExpected2; test7_2TokenExpected2.text = NULL; test7_2TokenExpected2.type = separator_value;
	t_token	test7_2TokenExpected3; test7_2TokenExpected3.text = NULL; test7_2TokenExpected3.type = eol;
	assert_svalue(0, compare_token(&test7_2TokenExpected1, (t_token*)ft_lstget(test7_2List, 0)->content), "test7_2 token identifier (,)");
	assert_svalue(0, compare_token(&test7_2TokenExpected2, (t_token*)ft_lstget(test7_2List, 1)->content), "test7_2 token identifier (,)");
	assert_svalue(0, compare_token(&test7_2TokenExpected3, (t_token*)ft_lstget(test7_2List, 2)->content), "test7_2 token eol");
	assert_address(NULL, test7_2List->next->next->next, "test7_2 token eol->next");
	ft_lstclear(&test7_2List, destroy_token2);
	assert_utils_separator();
}

void create_line_list_test(void)
{
	create_subtitle("create_line_list_test");




	//test 1 (empty file)
	int test1Fd = memfd_create("rt.rt", MFD_ALLOW_SEALING);
	if (test1Fd == -1)
		printf("memfd_create");
	char *test1StringFakeFile = "";
	write(test1Fd, test1StringFakeFile, strlen(test1StringFakeFile)); //the seek pointer is in the end;
	t_list *test1List = create_line_list(test1Fd);
	assert_address(NULL, test1List, "test1 token NULL");
	destroy_line_list(&test1List);
	close(test1Fd);
	assert_utils_separator();

	//test 2 (one blank line)
	int test2Fd = memfd_create("rt.rt", MFD_ALLOW_SEALING);
	if (test2Fd == -1)
		printf("memfd_create");
	char *test2StringFakeFile = " ";
	write(test2Fd, test2StringFakeFile, strlen(test2StringFakeFile));
	lseek(test2Fd, 0, SEEK_SET);
	t_list *test2List = create_line_list(test2Fd);
	assert_address(NULL, test2List, "test2 token NULL");
	ft_lstclear(&test2List, destroy_token2);
	close(test2Fd);
	assert_utils_separator();

	//test 2.1 (one blank line)
	int test2_1Fd = memfd_create("rt.rt", MFD_ALLOW_SEALING);
	if (test2_1Fd == -1)
		printf("memfd_create");
	char *test2_1StringFakeFile = "     ";
	write(test2_1Fd, test2_1StringFakeFile, strlen(test2_1StringFakeFile));
	lseek(test2_1Fd, 0, SEEK_SET);
	t_list *test2_1List = create_line_list(test2_1Fd);
	assert_address(NULL, test2_1List, "test2_1 token NULL");
	destroy_line_list(&test2_1List);
	close(test2_1Fd);
	assert_utils_separator();

	//test 2.2 (one blank line)
	int test2_2Fd = memfd_create("rt.rt", MFD_ALLOW_SEALING);
	if (test2_2Fd == -1)
		printf("memfd_create");
	char *test2_2StringFakeFile = "     \n";
	write(test2_2Fd, test2_2StringFakeFile, strlen(test2_2StringFakeFile));
	lseek(test2_2Fd, 0, SEEK_SET);
	t_list *test2_2List = create_line_list(test2_2Fd);
	assert_address(NULL, test2_2List, "test2_2 token NULL");
	destroy_line_list(&test2_2List);
	close(test2_2Fd);
	assert_utils_separator();

	//test 2.3 (two blank line)
	int test2_3Fd = memfd_create("rt.rt", MFD_ALLOW_SEALING);
	if (test2_3Fd == -1)
		printf("memfd_create");
	char *test2_3StringFakeFile = "     \n ";
	write(test2_3Fd, test2_3StringFakeFile, strlen(test2_3StringFakeFile));
	lseek(test2_3Fd, 0, SEEK_SET);
	t_list *test2_3List = create_line_list(test2_3Fd);
	assert_address(NULL, test2_3List, "test2_3 token NULL");
	destroy_line_list(&test2_3List);
	close(test2_3Fd);
	assert_utils_separator();

	//test 2.4 (two blank line)
	int test2_4Fd = memfd_create("rt.rt", MFD_ALLOW_SEALING);
	if (test2_4Fd == -1)
		printf("memfd_create");
	char *test2_4StringFakeFile = "     \n \n";
	write(test2_4Fd, test2_4StringFakeFile, strlen(test2_4StringFakeFile));
	lseek(test2_4Fd, 0, SEEK_SET);
	t_list *test2_4List = create_line_list(test2_4Fd);
	assert_address(NULL, test2_4List, "test2_4 token NULL");
	destroy_line_list(&test2_4List);
	close(test2_4Fd);
	assert_utils_separator();

	//test 2.5 (two blank line)
	int test2_5Fd = memfd_create("rt.rt", MFD_ALLOW_SEALING);
	if (test2_5Fd == -1)
		printf("memfd_create");
	char *test2_5StringFakeFile = "     \n  \n";
	write(test2_5Fd, test2_5StringFakeFile, strlen(test2_5StringFakeFile));
	lseek(test2_5Fd, 0, SEEK_SET);
	t_list *test2_5List = create_line_list(test2_5Fd);
	assert_address(NULL, test2_5List, "test2_5 token NULL");
	destroy_line_list(&test2_5List);
	close(test2_5Fd);
	assert_utils_separator();

	//test 3.1 (one line [valid])
	int test3_1Fd = memfd_create("rt.rt", MFD_ALLOW_SEALING);
	if (test3_1Fd == -1)
		printf("memfd_create");
	char *test3_1StringFakeFile = "  abc  ";
	write(test3_1Fd, test3_1StringFakeFile, strlen(test3_1StringFakeFile));
	lseek(test3_1Fd, 0, SEEK_SET);
	t_list *test3_1LineList = create_line_list(test3_1Fd);
	assert_uvalue(1, ((t_line*)test3_1LineList->content)->line_number,            "test3_1 line must be number 1");
	assert_uvalue(2, ft_lstsize(((t_line*)test3_1LineList->content)->token_list), "test3_1 token size list must be 2");
	destroy_line_list(&test3_1LineList);
	close(test3_1Fd);
	assert_utils_separator();


	//test 3.2 (two lines [valid])
	int test3_2Fd = memfd_create("rt.rt", MFD_ALLOW_SEALING);
	if (test3_2Fd == -1)
		printf("memfd_create");
	char *test3_2StringFakeFile = "  abc  \ndef";
	write(test3_2Fd, test3_2StringFakeFile, strlen(test3_2StringFakeFile));
	lseek(test3_2Fd, 0, SEEK_SET);
	t_list *test3_2List = create_line_list(test3_2Fd);
	assert_uvalue(1, ((t_line*)test3_2List->content)->line_number,       "test3_1 line must be number 1");
	assert_uvalue(2, ((t_line*)test3_2List->next->content)->line_number, "test3_1 line must be number 2");
	destroy_line_list(&test3_2List);
	close(test3_2Fd);
	assert_utils_separator();


	//test 3.3 (three lines [valid])
	int test3_3Fd = memfd_create("rt.rt", MFD_ALLOW_SEALING);
	if (test3_3Fd == -1)
		printf("memfd_create");
	char *test3_3StringFakeFile = "  abc1  \ndef2\n\nghi4";
	write(test3_3Fd, test3_3StringFakeFile, strlen(test3_3StringFakeFile));
	lseek(test3_3Fd, 0, SEEK_SET);
	t_list *test3_3List = create_line_list(test3_3Fd);
	assert_uvalue(1, ((t_line*)test3_3List->content)->line_number,             "test3_1 line must be number 1");
	assert_uvalue(2, ((t_line*)test3_3List->next->content)->line_number,       "test3_1 line must be number 2");
	assert_uvalue(4, ((t_line*)test3_3List->next->next->content)->line_number, "test3_1 line must be number 4");
	destroy_line_list(&test3_3List);
	close(test3_3Fd);
	assert_utils_separator();

	//test 3.4 (three lines [valid]) other test
	int test3_4Fd = memfd_create("rt.rt", MFD_ALLOW_SEALING);
	if (test3_4Fd == -1)
		printf("memfd_create");
	char *test3_4StringFakeFile = "  abc1,  \ndef2\n\nghi4";
	write(test3_4Fd, test3_4StringFakeFile, strlen(test3_4StringFakeFile));
	lseek(test3_4Fd, 0, SEEK_SET);
	t_list *test3_4List = create_line_list(test3_4Fd);
	assert_uvalue(1, ((t_line*)test3_4List->content)->line_number,             "test3_1 line must be number 1");
	assert_uvalue(2, ((t_line*)test3_4List->next->content)->line_number,       "test3_1 line must be number 2");
	assert_uvalue(4, ((t_line*)test3_4List->next->next->content)->line_number, "test3_1 line must be number 4");
	destroy_line_list(&test3_4List);
	close(test3_4Fd);
	assert_utils_separator();
}


void	lexer_test(int argc, char **argv)
{
	if (argc != 1 &&  strcmp(argv[1], "lexer_test") != 0)
		return ;
	create_title("lexer_test");

	prepared_line_test();
	line_create_tokens_test();
	create_line_list_test();
}
